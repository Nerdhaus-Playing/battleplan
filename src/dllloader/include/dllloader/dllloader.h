#pragma once
#include <memory>
#include <string>

namespace nhp::aclt::dllloader
{
    class DllLoaderImpl;

    class DllLoader
    {
    public:
        DllLoader() = delete;
        DllLoader(const std::string& filePath);
        ~DllLoader();

    private:
        std::unique_ptr<DllLoaderImpl> m_impl;
    };
}