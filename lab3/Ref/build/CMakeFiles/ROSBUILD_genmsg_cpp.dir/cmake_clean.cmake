FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/Ref/msg"
  "CMakeFiles/ROSBUILD_genmsg_cpp"
  "../msg_gen/cpp/include/Ref/CurrentStatus.h"
  "../msg_gen/cpp/include/Ref/BotToRef.h"
  "../msg_gen/cpp/include/Ref/HoverBot.h"
  "../msg_gen/cpp/include/Ref/BotStatus.h"
  "../msg_gen/cpp/include/Ref/Position.h"
  "../msg_gen/cpp/include/Ref/controls.h"
  "../msg_gen/cpp/include/Ref/image.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
