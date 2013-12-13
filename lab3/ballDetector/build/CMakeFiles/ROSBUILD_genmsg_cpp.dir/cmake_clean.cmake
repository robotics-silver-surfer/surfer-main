FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/ballDetector/msg"
  "CMakeFiles/ROSBUILD_genmsg_cpp"
  "../msg_gen/cpp/include/ballDetector/ballDebug.h"
  "../msg_gen/cpp/include/ballDetector/debugTimes.h"
  "../msg_gen/cpp/include/ballDetector/ballLocation.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
