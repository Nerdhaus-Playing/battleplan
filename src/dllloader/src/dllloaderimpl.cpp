#include "dllloaderimpl.h"

using namespace nhp::aclt::dllloader;


DllLoaderImpl::DllLoaderImpl(const std::string& filePath):
    m_library(filePath)
{
    
}
DllLoaderImpl::~DllLoaderImpl()
{

}
