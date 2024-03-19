#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cstdint>
#include <fstream>
#include <map>
#include <vector>
#include <memory>

namespace ntt
{
    template <typename T>
    using Ref = std::shared_ptr<T>;

    template <typename T, typename... Args>
    Ref<T> MakeRef(Args &&...args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    template <typename T>
    using Scope = std::unique_ptr<T>;

    template <typename T, typename... Args>
    Ref<T> MakeScope(Args &&...args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template <typename T>
    using List = std::vector<T>;

    template <typename K, typename V>
    using Dictionary = std::map<K, V>;

    template <typename T, typename U>
    Ref<T> Cast(const Ref<U> &ref)
    {
        return std::dynamic_pointer_cast<T>(ref);
    }
} // namespace ntt
