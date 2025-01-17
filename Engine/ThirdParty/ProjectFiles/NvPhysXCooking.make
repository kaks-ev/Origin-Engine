# Alternative GNU Make project makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

.PHONY: clean prebuild

SHELLTYPE := posix
ifeq (.exe,$(findstring .exe,$(ComSpec)))
	SHELLTYPE := msdos
endif

# Configurations
# #############################################

RESCOMP = windres
INCLUDES += -I../nvphysx/physx/include -I../nvphysx/physx/source/common/include -I../nvphysx/physx/source/common/src -I../nvphysx/physx/source/geomutils/include -I../nvphysx/physx/source/geomutils/src -I../nvphysx/physx/source/geomutils/src/contact -I../nvphysx/physx/source/geomutils/src/common -I../nvphysx/physx/source/geomutils/src/convex -I../nvphysx/physx/source/geomutils/src/distance -I../nvphysx/physx/source/geomutils/src/sweep -I../nvphysx/physx/source/geomutils/src/gjk -I../nvphysx/physx/source/geomutils/src/intersection -I../nvphysx/physx/source/geomutils/src/mesh -I../nvphysx/physx/source/geomutils/src/hf -I../nvphysx/physx/source/geomutils/src/pcm -I../nvphysx/physx/source/geomutils/src/ccd -I../nvphysx/physx/source/physxcooking/src -I../nvphysx/physx/source/physxcooking/src/mesh -I../nvphysx/physx/source/physxcooking/src/convex -I../nvphysx/physx/source/physxgpu/include -I../nvphysx/physx/source/foundation/include
FORCE_INCLUDE +=
ALL_CPPFLAGS += $(CPPFLAGS) -MD -MP $(DEFINES) $(INCLUDES)
ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
LINKCMD = $(AR) -rcs "$@" $(OBJECTS)
define PREBUILDCMDS
endef
define PRELINKCMDS
endef
define POSTBUILDCMDS
endef

ifeq ($(config),debug)
TARGETDIR = ../../Build/VS2022/Debug/Binaries/ThirdParty
TARGET = $(TARGETDIR)/NvPhysXCooking.lib
OBJDIR = ../../Build/VS2022/Debug/Objs/ThirdParty/NvPhysXCooking
DEFINES += -DWIN32 -DWIN64 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -D_WINSOCK_DEPRECATED_NO_WARNINGS -DPX_PHYSX_GPU_SHARED_LIB_NAME=PhysXGpu_64.dll -DPX_PHYSX_STATIC_LIB -DPX_SUPPORT_PVD=1 -DPX_COOKING -DPX_DEBUG=1 -DPX_CHECKED=1 -DPX_NVTX=0 -D_DEBUG
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -O0 -g
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -O0 -g -std=c++17
LIBS += ../../Build/VS2022/Debug/Binaries/ThirdParty/NvPhysXCommon.lib ../../Build/VS2022/Debug/Binaries/ThirdParty/NvPhysXFoundation.lib
LDDEPS += ../../Build/VS2022/Debug/Binaries/ThirdParty/NvPhysXCommon.lib ../../Build/VS2022/Debug/Binaries/ThirdParty/NvPhysXFoundation.lib
ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -m64

else ifeq ($(config),release)
TARGETDIR = ../../Build/VS2022/Release/Binaries/ThirdParty
TARGET = $(TARGETDIR)/NvPhysXCooking.lib
OBJDIR = ../../Build/VS2022/Release/Objs/ThirdParty/NvPhysXCooking
DEFINES += -DWIN32 -DWIN64 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -D_WINSOCK_DEPRECATED_NO_WARNINGS -DPX_PHYSX_GPU_SHARED_LIB_NAME=PhysXGpu_64.dll -DPX_PHYSX_STATIC_LIB -DPX_SUPPORT_PVD=1 -DPX_COOKING -D_HAS_ITERATOR_DEBUGGING=0 -D_ITERATOR_DEBUG_LEVEL=0 -DPX_CHECKED=1 -DPX_NVTX=0 -DNDEBUG
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -O2 -g
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -O2 -g -std=c++17
LIBS += ../../Build/VS2022/Release/Binaries/ThirdParty/NvPhysXCommon.lib ../../Build/VS2022/Release/Binaries/ThirdParty/NvPhysXFoundation.lib
LDDEPS += ../../Build/VS2022/Release/Binaries/ThirdParty/NvPhysXCommon.lib ../../Build/VS2022/Release/Binaries/ThirdParty/NvPhysXFoundation.lib
ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -m64

else ifeq ($(config),dist)
TARGETDIR = ../../Build/VS2022/Dist/Binaries/ThirdParty
TARGET = $(TARGETDIR)/NvPhysXCooking.lib
OBJDIR = ../../Build/VS2022/Dist/Objs/ThirdParty/NvPhysXCooking
DEFINES += -DWIN32 -DWIN64 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -D_WINSOCK_DEPRECATED_NO_WARNINGS -DPX_PHYSX_GPU_SHARED_LIB_NAME=PhysXGpu_64.dll -DPX_PHYSX_STATIC_LIB -DPX_SUPPORT_PVD=1 -DPX_COOKING -D_HAS_ITERATOR_DEBUGGING=0 -D_ITERATOR_DEBUG_LEVEL=0 -DPX_CHECKED=1 -DNDEBUG
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -O2
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -O2 -std=c++17
LIBS += ../../Build/VS2022/Dist/Binaries/ThirdParty/NvPhysXCommon.lib ../../Build/VS2022/Dist/Binaries/ThirdParty/NvPhysXFoundation.lib
LDDEPS += ../../Build/VS2022/Dist/Binaries/ThirdParty/NvPhysXCommon.lib ../../Build/VS2022/Dist/Binaries/ThirdParty/NvPhysXFoundation.lib
ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -m64 -s

endif

# Per File Configurations
# #############################################


# File sets
# #############################################

GENERATED :=
OBJECTS :=

GENERATED += $(OBJDIR)/Cooking.o
GENERATED += $(OBJDIR)/WindowsCookingDelayLoadHook.o
OBJECTS += $(OBJDIR)/Cooking.o
OBJECTS += $(OBJDIR)/WindowsCookingDelayLoadHook.o

# Rules
# #############################################

all: $(TARGET)
	@:

$(TARGET): $(GENERATED) $(OBJECTS) $(LDDEPS) | $(TARGETDIR)
	$(PRELINKCMDS)
	@echo Linking NvPhysXCooking
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning NvPhysXCooking
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(GENERATED)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(GENERATED)) del /s /q $(subst /,\\,$(GENERATED))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild: | $(OBJDIR)
	$(PREBUILDCMDS)

ifneq (,$(PCH))
$(OBJECTS): $(GCH) | $(PCH_PLACEHOLDER)
$(GCH): $(PCH) | prebuild
	@echo $(notdir $<)
	$(SILENT) $(CXX) -x c++-header $(ALL_CXXFLAGS) -o "$@" -MF "$(@:%.gch=%.d)" -c "$<"
$(PCH_PLACEHOLDER): $(GCH) | $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) touch "$@"
else
	$(SILENT) echo $null >> "$@"
endif
else
$(OBJECTS): | prebuild
endif


# File Rules
# #############################################

$(OBJDIR)/Cooking.o: ../nvphysx/physx/source/physxcooking/src/Cooking.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/WindowsCookingDelayLoadHook.o: ../nvphysx/physx/source/physxcooking/src/windows/WindowsCookingDelayLoadHook.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

-include $(OBJECTS:%.o=%.d)
ifneq (,$(PCH))
  -include $(PCH_PLACEHOLDER).d
endif