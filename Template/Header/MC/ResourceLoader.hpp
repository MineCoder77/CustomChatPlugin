// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Core.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ResourceLoader {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_RESOURCELOADER
public:
    class ResourceLoader& operator=(class ResourceLoader const&) = delete;
    ResourceLoader(class ResourceLoader const&) = delete;
    ResourceLoader() = delete;
#endif

public:
    /*0*/ virtual ~ResourceLoader();
    /*1*/ virtual bool load(class ResourceLocationPair const&, std::string&, std::vector<std::string> const&) const;
    /*2*/ virtual void __unk_vfn_0();
    /*3*/ virtual void __unk_vfn_1();
    /*4*/ virtual void __unk_vfn_2() = 0;
    /*5*/ virtual void __unk_vfn_3() = 0;
    /*6*/ virtual void __unk_vfn_4() = 0;
    /*7*/ virtual class Core::PathBuffer<std::string > getPath(class ResourceLocation const&) const;
    /*8*/ virtual class Core::PathBuffer<std::string > getPath(class ResourceLocation const&, std::vector<std::string> const&) const;
    /*9*/ virtual class Core::PathBuffer<std::string > getPathContainingResource(class ResourceLocation const&) const;
    /*10*/ virtual class Core::PathBuffer<std::string > getPathContainingResource(class ResourceLocation const&, std::vector<std::string>) const;
    /*11*/ virtual struct std::pair<int, std::string const& > getPackStackIndexOfResource(class ResourceLocation const&, std::vector<std::string> const&) const;
    /*
    inline bool isInStreamableLocation(class ResourceLocation const& a0, std::vector<std::string> const& a1) const{
        bool (ResourceLoader::*rv)(class ResourceLocation const&, std::vector<std::string> const&) const;
        *((void**)&rv) = dlsym("?isInStreamableLocation@ResourceLoader@@UEBA_NAEBVResourceLocation@@AEBV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@@Z");
        return (this->*rv)(std::forward<class ResourceLocation const&>(a0), std::forward<std::vector<std::string> const&>(a1));
    }
    inline bool isInStreamableLocation(class ResourceLocation const& a0) const{
        bool (ResourceLoader::*rv)(class ResourceLocation const&) const;
        *((void**)&rv) = dlsym("?isInStreamableLocation@ResourceLoader@@UEBA_NAEBVResourceLocation@@@Z");
        return (this->*rv)(std::forward<class ResourceLocation const&>(a0));
    }
    inline  ~ResourceLoader(){
         (ResourceLoader::*rv)();
        *((void**)&rv) = dlsym("??1ResourceLoader@@UEAA@XZ");
        return (this->*rv)();
    }
    */

protected:

private:

};