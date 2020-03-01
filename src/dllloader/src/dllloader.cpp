#include "dllloader/dllloader.h"
#include "dllloaderimpl.h"

using namespace nhp::aclt::dllloader;

DllLoader::DllLoader(const std::string& filePath)
{
    m_impl = std::make_unique<DllLoaderImpl>(filePath);
}

DllLoader::~DllLoader() = default;