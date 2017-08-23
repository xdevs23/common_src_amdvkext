/*
***************************************************************************************************
*
*  Copyright (c) 2014-2017 Advanced Micro Devices, Inc. All rights reserved.
*
**************************************************************************************************/
/**
 **********************************************************************************************************************
 * @file  vk_amd_gpa_interface.h
 * @brief Header for VK_AMD_gpa_interface extension.  This extension exists as the Vulkan-specific backend to service
 *        AMD's GPUPerfAPI performance measurement API.  This extension is only supported when used by GPUPerfAPI.
 **********************************************************************************************************************
 */
#ifndef VK_AMD_GPA_INTERFACE_H_
#define VK_AMD_GPA_INTERFACE_H_

#include "vk_internal_ext_helper.h"

#define VK_AMD_GPA_INTERFACE_SPEC_VERSION                1
#define VK_AMD_GPA_INTERFACE_EXTENSION_NAME              "VK_AMD_gpa_interface"

#define VK_AMD_GPA_INTERFACE_EXTENSION_NUMBER            134

#define VK_AMD_GPA_INTERFACE_ENUM(type, offset) \
    VK_EXTENSION_ENUM(VK_AMD_GPA_INTERFACE_EXTENSION_NUMBER, type, offset)

typedef enum VkGpaSqShaderStageFlagBitsAMD
{
    VK_GPA_SQ_SHADER_STAGE_PS_BIT_AMD             = 0x00000001,
    VK_GPA_SQ_SHADER_STAGE_VS_BIT_AMD             = 0x00000002,
    VK_GPA_SQ_SHADER_STAGE_GS_BIT_AMD             = 0x00000004,
    VK_GPA_SQ_SHADER_STAGE_ES_BIT_AMD             = 0x00000008,
    VK_GPA_SQ_SHADER_STAGE_HS_BIT_AMD             = 0x00000010,
    VK_GPA_SQ_SHADER_STAGE_LS_BIT_AMD             = 0x00000020,
    VK_GPA_SQ_SHADER_STAGE_CS_BIT_AMD             = 0x00000040,
    VK_GPA_SQ_SHADER_STAGE_FLAG_BITS_MAX_ENUM_AMD = 0x7FFFFFFF
} VkGpaSqShaderStageFlagBitsAMD;

typedef VkFlags VkGpaSqShaderStageFlags;

typedef enum VkGpaPerfBlockAMD
{
    VK_GPA_PERF_BLOCK_CPF_AMD             = 0,
    VK_GPA_PERF_BLOCK_IA_AMD              = 1,
    VK_GPA_PERF_BLOCK_VGT_AMD             = 2,
    VK_GPA_PERF_BLOCK_PA_AMD              = 3,
    VK_GPA_PERF_BLOCK_SC_AMD              = 4,
    VK_GPA_PERF_BLOCK_SPI_AMD             = 5,
    VK_GPA_PERF_BLOCK_SQ_AMD              = 6,
    VK_GPA_PERF_BLOCK_SX_AMD              = 7,
    VK_GPA_PERF_BLOCK_TA_AMD              = 8,
    VK_GPA_PERF_BLOCK_TD_AMD              = 9,
    VK_GPA_PERF_BLOCK_TCP_AMD             = 10,
    VK_GPA_PERF_BLOCK_TCC_AMD             = 11,
    VK_GPA_PERF_BLOCK_TCA_AMD             = 12,
    VK_GPA_PERF_BLOCK_DB_AMD              = 13,
    VK_GPA_PERF_BLOCK_CB_AMD              = 14,
    VK_GPA_PERF_BLOCK_GDS_AMD             = 15,
    VK_GPA_PERF_BLOCK_SRBM_AMD            = 16,
    VK_GPA_PERF_BLOCK_GRBM_AMD            = 17,
    VK_GPA_PERF_BLOCK_GRBM_SE_AMD         = 18,
    VK_GPA_PERF_BLOCK_RLC_AMD             = 19,
    VK_GPA_PERF_BLOCK_DMA_AMD             = 20,
    VK_GPA_PERF_BLOCK_MC_AMD              = 21,
    VK_GPA_PERF_BLOCK_CPG_AMD             = 22,
    VK_GPA_PERF_BLOCK_CPC_AMD             = 23,
    VK_GPA_PERF_BLOCK_WD_AMD              = 24,
    VK_GPA_PERF_BLOCK_TCS_AMD             = 25,
    VK_GPA_PERF_BLOCK_ATC_AMD             = 26,
    VK_GPA_PERF_BLOCK_ATC_L2_AMD          = 27,
    VK_GPA_PERF_BLOCK_MC_VM_L2_AMD        = 28,
    VK_GPA_PERF_BLOCK_EA_AMD              = 29,
    VK_GPA_PERF_BLOCK_RPB_AMD             = 30,
    VK_GPA_PERF_BLOCK_RMI_AMD             = 31,
    VK_GPA_PERF_BLOCK_BEGIN_RANGE_AMD     = VK_GPA_PERF_BLOCK_CPF_AMD,
    VK_GPA_PERF_BLOCK_END_RANGE_AMD       = VK_GPA_PERF_BLOCK_RMI_AMD,
    VK_GPA_PERF_BLOCK_RANGE_SIZE_AMD      = (VK_GPA_PERF_BLOCK_END_RANGE_AMD - VK_GPA_PERF_BLOCK_BEGIN_RANGE_AMD + 1),
    VK_GPA_PERF_BLOCK_MAX_ENUM_AMD        = 0x7FFFFFFF
} VkGpaPerfBlockAMD;

typedef VkFlags VkGpaSqShaderStageFlagsAMD;

typedef struct VkGpaPerfBlockPropertiesAMD
{
    VkGpaPerfBlockAMD               blockType;
    VkFlags                         flags;
    uint32_t                        instanceCount;
    uint32_t                        maxEventID;
    uint32_t                        maxGlobalOnlyCounters;
    uint32_t                        maxGlobalSharedCounters;
    uint32_t                        maxStreamingCounters;
} VkGpaPerfBlockPropertiesAMD;

typedef struct VkPhysicalDeviceGpaFeaturesAMD
{
    VkStructureType                      sType;
    const void*                          pNext;

    VkBool32                             perfCounters;
    VkBool32                             streamingPerfCounters;
    VkBool32                             sqThreadTracing;
    VkBool32                             clockModes;
} VkPhysicalDeviceGpaFeaturesAMD;

typedef struct VkPhysicalDeviceGpaPropertiesAMD
{
    VkStructureType                      sType;
    const void*                          pNext;

    VkFlags                              flags;

    VkDeviceSize                         maxSqttSeBufferSize;
    uint32_t                             shaderEngineCount;
    uint32_t                             perfBlockCount;
    VkGpaPerfBlockPropertiesAMD*         pPerfBlocks;
} VkPhysicalDeviceGpaPropertiesAMD;

typedef enum VkGpaSampleTypeAMD
{
    VK_GPA_SAMPLE_TYPE_CUMULATIVE_AMD = 0,
    VK_GPA_SAMPLE_TYPE_TRACE_AMD      = 1,
    VK_GPA_SAMPLE_TYPE_TIMING_AMD     = 2,

    VK_GPA_SAMPLE_TYPE_BEGIN_RANGE_AMD = VK_GPA_SAMPLE_TYPE_CUMULATIVE_AMD,
    VK_GPA_SAMPLE_TYPE_END_RANGE_AMD   = VK_GPA_SAMPLE_TYPE_TIMING_AMD,
    VK_GPA_SAMPLE_TYPE_RANGE_SIZE_AMD  = (VK_GPA_SAMPLE_TYPE_END_RANGE_AMD - VK_GPA_SAMPLE_TYPE_BEGIN_RANGE_AMD + 1),
    VK_GPA_SAMPLE_TYPE_MAX_ENUM_AMD    = 0x7FFFFFFF
} VkGpaSampleTypeAMD;

typedef struct VkGpaPerfCounterAMD
{
    VkGpaPerfBlockAMD           blockType;
    uint32_t                    blockInstance;
    uint32_t                    eventID;
} VkGpaPerfCounterAMD;

typedef VkFlags VkGpaSampleFlagsAMD;

typedef struct VkGpaSampleBeginInfoAMD
{
    VkStructureType                    sType;
    const void*                        pNext;

    VkGpaSampleTypeAMD                 sampleType;

    VkBool32                           sampleInternalOperations;
    VkBool32                           cacheFlushOnCounterCollection;
    VkBool32                           sqShaderMaskEnable;

    VkGpaSqShaderStageFlagsAMD         sqShaderMask;

    uint32_t                           perfCounterCount;
    const VkGpaPerfCounterAMD*         pPerfCounters;
    uint32_t                           streamingPerfTraceSampleInterval;
    VkDeviceSize                       perfCounterDeviceMemoryLimit;

    VkBool32                           sqThreadTraceEnable;
    VkBool32                           sqThreadTraceSuppressInstructionTokens;
    VkDeviceSize                       sqThreadTraceDeviceMemoryLimit;

    VkPipelineStageFlagBits            timingPreSample;
    VkPipelineStageFlagBits            timingPostSample;
} VkGpaSampleBeginInfoAMD;

typedef enum VkGpaDeviceClockModeAMD
{
    VK_GPA_DEVICE_CLOCK_MODE_DEFAULT_AMD     = 0,
    VK_GPA_DEVICE_CLOCK_MODE_QUERY_AMD       = 1,
    VK_GPA_DEVICE_CLOCK_MODE_PROFILING_AMD   = 2,
    VK_GPA_DEVICE_CLOCK_MODE_MIN_MEMORY_AMD  = 3,
    VK_GPA_DEVICE_CLOCK_MODE_MIN_ENGINE_AMD  = 4,
    VK_GPA_DEVICE_CLOCK_MODE_PEAK_AMD        = 5,

    VK_GPA_DEVICE_CLOCK_MODE_BEGIN_RANGE_AMD = VK_GPA_DEVICE_CLOCK_MODE_DEFAULT_AMD,
    VK_GPA_DEVICE_CLOCK_MODE_END_RANGE_AMD   = VK_GPA_DEVICE_CLOCK_MODE_PEAK_AMD,
    VK_GPA_DEVICE_CLOCK_MODE_RANGE_SIZE_AMD  = (VK_GPA_DEVICE_CLOCK_MODE_END_RANGE_AMD - VK_GPA_DEVICE_CLOCK_MODE_BEGIN_RANGE_AMD + 1),
    VK_GPA_DEVICE_CLOCK_MODE_MAX_ENUM_AMD    = 0x7FFFFFFF
} VkGpaDeviceClockModeAMD;

typedef struct VkGpaDeviceClockModeInfoAMD
{
    VkStructureType                     sType;
    const void*                         pNext;

    VkGpaDeviceClockModeAMD             clockMode;
    float                               memoryClockRatioToPeak;
    float                               engineClockRatioToPeak;
} VkGpaDeviceClockModeInfoAMD;

VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkGpaSessionAMD)

typedef struct VkGpaSessionCreateInfoAMD
{
    VkStructureType         sType;
    const void*             pNext;

    VkGpaSessionAMD         secondaryCopySource;
} VkGpaSessionCreateInfoAMD;

typedef VkResult(VKAPI_PTR *PFN_vkCreateGpaSessionAMD)(
    VkDevice                                    device,
    const VkGpaSessionCreateInfoAMD*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkGpaSessionAMD*                            pGpaSession);

typedef void (VKAPI_PTR *PFN_vkDestroyGpaSessionAMD)(
    VkDevice                                    device,
    VkGpaSessionAMD                             gpaSession,
    const VkAllocationCallbacks*                pAllocator);

typedef VkResult (VKAPI_PTR *PFN_vkSetGpaDeviceClockModeAMD)(
    VkDevice                                    device,
    VkGpaDeviceClockModeInfoAMD*                pInfo);

typedef VkResult (VKAPI_PTR *PFN_vkCmdBeginGpaSessionAMD)(
    VkCommandBuffer                             commandBuffer,
    VkGpaSessionAMD                             gpaSession);

typedef VkResult (VKAPI_PTR *PFN_vkCmdEndGpaSessionAMD)(
    VkCommandBuffer                             commandBuffer,
    VkGpaSessionAMD                             gpaSession);

typedef VkResult (VKAPI_PTR *PFN_vkCmdBeginGpaSampleAMD)(
    VkCommandBuffer                             commandBuffer,
    VkGpaSessionAMD                             gpaSession,
    const VkGpaSampleBeginInfoAMD*              pGpaSampleBeginInfo,
    uint32_t*                                   pSampleID);

typedef void (VKAPI_PTR *PFN_vkCmdEndGpaSampleAMD)(
    VkCommandBuffer                             commandBuffer,
    VkGpaSessionAMD                             gpaSession,
    uint32_t                                    sampleID);

typedef VkResult (VKAPI_PTR *PFN_vkGetGpaSessionStatusAMD)(
    VkDevice                                    device,
    VkGpaSessionAMD                             gpaSession);

typedef VkResult (VKAPI_PTR *PFN_vkGetGpaSessionResultsAMD)(
    VkDevice                                    device,
    VkGpaSessionAMD                             gpaSession,
    uint32_t                                    sampleID,
    size_t*                                     pSizeInBytes,
    void*                                       pData);

typedef VkResult(VKAPI_PTR *PFN_vkResetGpaSessionAMD)(
    VkDevice                                    device,
    VkGpaSessionAMD                             gpaSession);

typedef void (VKAPI_PTR *PFN_vkCmdCopyGpaSessionResultsAMD)(
    VkCommandBuffer                             commandBuffer,
    VkGpaSessionAMD                             gpaSession);

#define VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GPA_FEATURES_AMD   VK_AMD_GPA_INTERFACE_ENUM(VkStructureType, 0)
#define VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GPA_PROPERTIES_AMD VK_AMD_GPA_INTERFACE_ENUM(VkStructureType, 1)
#define VK_STRUCTURE_TYPE_GPA_SAMPLE_BEGIN_INFO_AMD          VK_AMD_GPA_INTERFACE_ENUM(VkStructureType, 2)
#define VK_STRUCTURE_TYPE_GPA_SESSION_CREATE_INFO_AMD        VK_AMD_GPA_INTERFACE_ENUM(VkStructureType, 3)
#define VK_STRUCTURE_TYPE_GPA_DEVICE_CLOCK_MODE_INFO_AMD     VK_AMD_GPA_INTERFACE_ENUM(VkStructureType, 4)

#endif /* VK_AMD_GPA_H_ */