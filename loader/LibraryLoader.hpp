#pragma once
#include <NTTEngine/Common/Common.hpp>
#include <functional>
#include <iostream>

#ifdef WIN32
#include <Windows.h>
#endif

namespace ntt::loader
{
    template <typename T>
    class LibraryLoader
    {
    public:
        LibraryLoader(const char *path, const char *name)
            : m_Path(path)
        {
            m_Module = LoadLibraryA(path);

            if (m_Module == NULL)
            {
                std::cerr << "Failed to load library: " << path << std::endl;
                exit(-1);
            }

            string::String initStr("Init%s", name);
            string::String getInstanceStr("Get%sInstance", name);
            string::String releaseStr("Release%s", name);

            auto initFuncAddress = (void (*)())GetProcAddress(m_Module,
                                                              initStr.GetValue());
            if (initFuncAddress == NULL)
            {
                LoadError(initStr.GetValue());
            }
            m_InitFunc = std::function<void()>(initFuncAddress);

            auto getInstanceFuncAddress = (T * (*)()) GetProcAddress(
                m_Module,
                getInstanceStr.GetValue());
            if (getInstanceFuncAddress == NULL)
            {
                LoadError(getInstanceStr.GetValue());
            }
            m_GetInstanceFunc = std::function<T *()>(getInstanceFuncAddress);

            auto releaseFuncAddress = (void (*)())GetProcAddress(m_Module,
                                                                 releaseStr.GetValue());
            if (releaseFuncAddress == NULL)
            {
                LoadError(releaseStr.GetValue());
            }
            m_ReleaseFunc = std::function<void()>(releaseFuncAddress);
        }

        ~LibraryLoader()
        {
            FreeLibrary(m_Module);
        }

        void Init()
        {
            m_InitFunc();
        }

        T *GetInstance()
        {
            return m_GetInstanceFunc();
        }

        void Release()
        {
            m_ReleaseFunc();
        }

    protected:
        void LoadError(const char *name)
        {
            std::cerr << "Failed to load " << name
                      << " function from library: " << m_Path << std::endl;
            FreeLibrary(m_Module);
            exit(-1);
        }

    private:
#ifdef WIN32
        std::string m_Path;
        HMODULE m_Module;
        std::function<void()> m_InitFunc;
        std::function<T *()> m_GetInstanceFunc;
        std::function<void()> m_ReleaseFunc;
#endif
    };
} // namespace ntt::loader
