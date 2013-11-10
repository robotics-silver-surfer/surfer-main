FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/ballDetector/msg"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/ballDetector/msg/__init__.py"
  "../src/ballDetector/msg/_debugTimes.py"
  "../src/ballDetector/msg/_ballLocation.py"
  "../src/ballDetector/msg/_ballDebug.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
