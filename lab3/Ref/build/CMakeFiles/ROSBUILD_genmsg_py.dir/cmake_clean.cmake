FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/Ref/msg"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/Ref/msg/__init__.py"
  "../src/Ref/msg/_BotStatus.py"
  "../src/Ref/msg/_BotToRef.py"
  "../src/Ref/msg/_HoverBot.py"
  "../src/Ref/msg/_image.py"
  "../src/Ref/msg/_Position.py"
  "../src/Ref/msg/_controls.py"
  "../src/Ref/msg/_CurrentStatus.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
