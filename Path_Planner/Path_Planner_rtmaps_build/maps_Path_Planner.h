#ifndef RTW_HEADER_maps_Path_Planner_h_
#define RTW_HEADER_maps_Path_Planner_h_
#ifdef _MSC_VER
#if _MSC_VER < 1900
#error "In order to compile this code, you must use Visual Studio >= 2015 compiler"
#endif

#else
#if __cplusplus < 201103L
#error "In order to compile this code, you must use a C++11 compiler (e.g. GCC >= 5) and make sure that the '-std=c++11' (or '-std=c++14' or '-std=c++17' etc.) compiler flag is used"
#endif
#endif

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <map>
#include <mutex>
#include <string>
#include <type_traits>
#include <vector>
#include <maps.hpp>
#include <maps_type_traits.hpp>
#include <maps_macros.hpp>
#include <maps/input_reader/maps_input_reader.hpp>
#define G_MODEL_INPUT_COUNT            5
#define G_MODEL_OUTPUT_COUNT           5
#define G_MODEL_PARAM_COUNT            6

// standard io info
#define G_IO_SUFFIX_VECTOR_SIZE        "_size"
#define G_IO_SUFFIX_TIMESTAMP          "_ts"
#define G_IO_SUFFIX_FREQUENCY          "_freq"
#define G_IO_SUFFIX_QUALITY            "_qual"
#define G_IO_SUFFIX_MISC1              "_misc1"
#define G_IO_SUFFIX_MISC2              "_misc2"
#define G_IO_SUFFIX_MISC3              "_misc3"

// iplimage
#define G_IO_SUFFIX_IPLIMAGE           "_IplImage"
#define G_IO_SUFFIX_IPLIMAGE_SIZE      "_IplImageSize"
#define G_IO_SUFFIX_IPLIMAGE_CHANNEL_SEQ "_IplImageChannelSeq"

// Currently not supported
//#define G_IO_SUFFIX_IPLIMAGE_DATA_ORDER  "_IplImageDataOrder"  // Currently: Planar (IPL_DATA_ORDER_PLANE)
//#define G_IO_SUFFIX_IPLIMAGE_DEPTH       "_IplImageDepth"      // Currently: uint8 (IPL_DEPTH_8U)
//#define G_IO_SUFFIX_IPLIMAGE_ALIGN       "_IplImageAlign"      // Currently: unaligned when copied to Matlab, aligned (IPL_ALIGN_QWORD) when copied to RTMaps
enum class SkTypeId
{
  t_double = 0,
  t_single = 1,
  t_int8 = 2,
  t_uint8 = 3,
  t_int16 = 4,
  t_uint16 = 5,
  t_int32 = 6,
  t_uint32 = 7,
  t_bool = 8,
  t_struct = 100
};

struct Struct_t {
};

using TypeID_Value = int;
template <typename T> struct TypeID_Wrapper {
};

template <> struct TypeID_Wrapper<double > : std::integral_constant<TypeID_Value,
  1000>{
};

template <> struct TypeID_Wrapper<float > : std::integral_constant<TypeID_Value,
  1001>{
};

template <> struct TypeID_Wrapper<int8_t > : std::integral_constant<TypeID_Value,
  1002>{
};

template <> struct TypeID_Wrapper<uint8_t > : std::integral_constant<
  TypeID_Value, 1003>{
};

template <> struct TypeID_Wrapper<int16_t > : std::integral_constant<
  TypeID_Value, 1004>{
};

template <> struct TypeID_Wrapper<uint16_t> : std::integral_constant<
  TypeID_Value, 1005>{
};

template <> struct TypeID_Wrapper<int32_t > : std::integral_constant<
  TypeID_Value, 1006>{
};

template <> struct TypeID_Wrapper<uint32_t> : std::integral_constant<
  TypeID_Value, 1007>{
};

template <> struct TypeID_Wrapper<int64_t > : std::integral_constant<
  TypeID_Value, 1008>{
};

template <> struct TypeID_Wrapper<uint64_t> : std::integral_constant<
  TypeID_Value, 1009>{
};

template <> struct TypeID_Wrapper<bool > : std::integral_constant<TypeID_Value,
  1010>{
};

template <> struct TypeID_Wrapper<IplImage> : std::integral_constant<
  TypeID_Value, 1011>{
};

template <> struct TypeID_Wrapper<Struct_t> : std::integral_constant<
  TypeID_Value, 2000>{
};

template <typename TModelIOInfo>
    struct ImageInfo
{
  const TModelIOInfo* m_size;
  const TModelIOInfo* m_channelSeq;

  //const TModelIOInfo* m_dataOrder;
  //const TModelIOInfo* m_depth;
  //const TModelIOInfo* m_align;
};

struct ModelInputInfo
{
  std::string m_name;
  int m_index;
  int m_width;
  SkTypeId m_skTypeId;
  std::string m_skTypeName;
  int m_sizeOfType;
  void* m_dataPtr;
  using AssingmentCb = void (*) (const TypeID_Value /*mapsVoidPtrTypeId*/
    , const void*                      /*mapsInPtr*/
    , const size_t                     /*elementCount*/
    );
  AssingmentCb m_writeToModelInput;
  ModelInputInfo(
                 const std::string& name_,
                 const int index_,
                 const int width_,
                 const SkTypeId skTypeId_,
                 const std::string& skTypeName_,
                 const int sizeOfType_,
                 void* dataPtr,
                 const AssingmentCb writeToModelInput_
                 )
    : m_name(name_)
    , m_index(index_)
    , m_width(width_)
    , m_skTypeId(skTypeId_)
    , m_skTypeName(skTypeName_)
    , m_sizeOfType(sizeOfType_)
    , m_dataPtr(dataPtr)
    , m_writeToModelInput(writeToModelInput_)
  {
  }
};

struct ModelOutputInfo
{
  std::string m_name;
  int m_index;
  int m_width;
  SkTypeId m_skTypeId;
  std::string m_skTypeName;
  int m_sizeOfType;
  const void* m_dataPtr;
  using AssingmentCb = void (*) (const TypeID_Value /*mapsVoidPtrTypeId*/
    , void*                            /*mapsOutPtr*/
    , const size_t                     /*elementCount*/
    );
  AssingmentCb m_readFromModelOutput;
  ModelOutputInfo(
                  const std::string& name_,
                  const int index_,
                  const int width_,
                  const SkTypeId skTypeId_,
                  const std::string& skTypeName_,
                  const int sizeOfType_,
                  const void* dataPtr,
                  const AssingmentCb readFromModelOutput_
                  )
    : m_name(name_)
    , m_index(index_)
    , m_width(width_)
    , m_skTypeId(skTypeId_)
    , m_skTypeName(skTypeName_)
    , m_sizeOfType(sizeOfType_)
    , m_dataPtr(dataPtr)
    , m_readFromModelOutput(readFromModelOutput_)
  {
  }
};

struct ModelParamInfo
{
  std::string m_name;
  int m_index;
  int m_width;
  SkTypeId m_skTypeId;
  std::string m_defaultValue;
  const void* m_dataPtr;
  using AssingmentCb = bool (*) (MAPSProperty& mapsProp);
  AssingmentCb m_writeToModelParam;
  ModelParamInfo(
                 const std::string& name_,
                 const int index_,
                 const int width_,
                 const SkTypeId skTypeId_,
                 const std::string& defaultValue_,
                 const void* dataPtr,
                 const AssingmentCb writeToModelParam_
                 )
    : m_name(name_)
    , m_index(index_)
    , m_width(width_)
    , m_skTypeId(skTypeId_)
    , m_defaultValue(defaultValue_)
    , m_dataPtr(dataPtr)
    , m_writeToModelParam(writeToModelParam_)
  {
  }
};

struct ComponentInputInfo
{
  std::string m_name;
  TypeID_Value m_typeId;
  const ModelInputInfo* m_data = nullptr;
  const ModelInputInfo* m_vectorSize = nullptr;
  const ModelInputInfo* m_timestamp = nullptr;
  const ModelInputInfo* m_frequency = nullptr;
  const ModelInputInfo* m_quality = nullptr;
  const ModelInputInfo* m_misc1 = nullptr;
  const ModelInputInfo* m_misc2 = nullptr;
  const ModelInputInfo* m_misc3 = nullptr;
  std::vector<unsigned char> m_forcedValue;
  size_t m_forcedVectorSize;
  union {
    ImageInfo<ModelInputInfo> m_imageInfo;
  };

  explicit ComponentInputInfo(const std::string& name_) : m_name(name_)
  {
  }

  bool hasForcedValue() const
  {
    return !m_forcedValue.empty();
  }
};

struct ComponentOutputInfo
{
  std::string m_name;
  TypeID_Value m_typeId;
  const ModelOutputInfo* m_data = nullptr;
  const ModelOutputInfo* m_vectorSize = nullptr;
  const ModelOutputInfo* m_timestamp = nullptr;
  const ModelOutputInfo* m_frequency = nullptr;
  const ModelOutputInfo* m_quality = nullptr;
  const ModelOutputInfo* m_misc1 = nullptr;
  const ModelOutputInfo* m_misc2 = nullptr;
  const ModelOutputInfo* m_misc3 = nullptr;
  union {
    ImageInfo<ModelOutputInfo> m_imageInfo;
  };

  explicit ComponentOutputInfo(const std::string& name_) : m_name(name_)
  {
  }
};

#define ComponentClass                 maps_Path_Planner
#define ComponentName                  "Path_Planner"
#define ComponentVersion               "1.24"

class ComponentClass : public MAPSComponent
{
 public:
  enum class ExecMode : int64_t
  {
    Periodic = 0,
    TriggeredByFirstInput,
    PeriodicSamplingWhilePostProcessing
  };

  MAPS_COMPONENT_HEADER_CODE_WITHOUT_CONSTRUCTOR(ComponentClass)
    ComponentClass(const char* componentName, MAPSComponentDefinition& md);
  MAPS_COMPONENT_REGISTERING_HEADER_CODE(ComponentClass)
    ~ComponentClass() override;
  void Dynamic() override;
 private:
  // statics -------------------------------------------------------------------------------------

  // allow only a single instance of the component
  // this limitation might be removed in a future version
  static ComponentClass* s_instance;
  static std::mutex s_instanceMutex;

  //
  static std::vector<ModelInputInfo> s_skModelInputs;
  static std::vector<ModelOutputInfo> s_skModelOutputs;
  static std::vector<ModelParamInfo> s_skModelParams;

  //
  static std::vector<ComponentInputInfo> s_componentInputs;
  static std::vector<ComponentOutputInfo> s_componentOutputs;

  //
  static const MAPSDelay s_skModelStepSize;

  // instance members ----------------------------------------------------------------------------
  bool m_firstTime_Dynamic;
  ExecMode m_executionMode;
  std::unique_ptr<MAPS::InputReader> m_inputReader;
  std::map<MAPSInput*, const ComponentInputInfo*> m_inputMap;
  std::vector<MAPSInput*> m_dataInputs;
  std::vector<MAPSInput*> m_forcedDataInputs;
  std::map<MAPSOutput*, const ComponentOutputInfo*> m_outputMap;
  std::vector<MAPSOutput*> m_dataOutputs;
  bool m_deferredBuffersAllocated;

  // methods -------------------------------------------------------------------------------------

  // model and component I/O
  static void computeSkModelInputs();
  static void computeSkModelOutputs();
  static void computeSkModelProps();
  template <typename TSkModelIOInfo, typename TComponentIOInfo>
    static void computeComponentIO(const TSkModelIOInfo& modelIo,
    TComponentIOInfo& compIo);
  template <typename TComponentIOInfo>
    static void filterComponentIOs(std::vector<TComponentIOInfo>& compIos);
  template <typename TSkModelIOInfo, typename TComponentIOInfo>
    static void computeComponentIOs(const std::vector<TSkModelIOInfo>& modelIo,
    std::vector<TComponentIOInfo>& compIo);

  // allow only a single instance of the component
  // this limitation might be removed in a future version
  void setStaticInstance();
  void clearStaticInstance();

  // component I/O management
  void createProperties();
  void createProperties_modelParams();
  void createProperties_forcedInputValues();
  void createInputs();
  void createOutputs();
  void allocOutputBuffers_birth();
  void allocOutputBuffers_deferred();
  void createInputReader();

  // simulink-related operations
  void doSkModelStep();
  void initSkModel();
  void terminateSkModel();

  // processing the data in and out of the component's I/O and simulink's step function
  void processData(const MAPSTimestamp ts, MAPS::ArrayView<MAPS::InputElt<>>
                   inElts);
  void readInputs(const MAPSTimestamp ts, const MAPS::ArrayView<MAPS::InputElt<>>
                  & inElts);
  void readInput(const MAPS::InputElt<>& inElt, const ComponentInputInfo& info);
  void readForcedInputs(const MAPSTimestamp ts);
  void readForcedInput(const MAPSTimestamp ts, const ComponentInputInfo& info);
  void writeOutputs(const MAPSTimestamp ts);
  void writeOutput(const MAPSTimestamp ts, MAPS::OutputGuard<>& outGuard, const
                   ComponentOutputInfo& info);
};

#endif                                 /* RTW_HEADER_maps_Path_Planner_h_ */
