#pragma once
#include <string>
#include <boost/dll.hpp>


namespace nhp::aclt::dllloader
{
    class DllLoaderImpl
    {
    public:
        DllLoaderImpl() = delete;
        DllLoaderImpl(const std::string& filePath);
        ~DllLoaderImpl();

    private:
        boost::dll::shared_library m_library;
    };
}

/*
    Possible Dll Functions

    Init
    Finalize
    void Execute (const char *)
    void Status
    void List

*/