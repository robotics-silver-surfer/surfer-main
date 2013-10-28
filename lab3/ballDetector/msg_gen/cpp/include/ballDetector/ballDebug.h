/* Auto-generated by genmsg_cpp for file /home/courtney/groovy_ws/projects/ros/surfer-main/lab3/ballDetector/msg/ballDebug.msg */
#ifndef BALLDETECTOR_MESSAGE_BALLDEBUG_H
#define BALLDETECTOR_MESSAGE_BALLDEBUG_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"


namespace ballDetector
{
template <class ContainerAllocator>
struct ballDebug_ {
  typedef ballDebug_<ContainerAllocator> Type;

  ballDebug_()
  : sendDebugImages(false)
  , sendDebugTimes(false)
  {
  }

  ballDebug_(const ContainerAllocator& _alloc)
  : sendDebugImages(false)
  , sendDebugTimes(false)
  {
  }

  typedef uint8_t _sendDebugImages_type;
  uint8_t sendDebugImages;

  typedef uint8_t _sendDebugTimes_type;
  uint8_t sendDebugTimes;


  typedef boost::shared_ptr< ::ballDetector::ballDebug_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ballDetector::ballDebug_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct ballDebug
typedef  ::ballDetector::ballDebug_<std::allocator<void> > ballDebug;

typedef boost::shared_ptr< ::ballDetector::ballDebug> ballDebugPtr;
typedef boost::shared_ptr< ::ballDetector::ballDebug const> ballDebugConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::ballDetector::ballDebug_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::ballDetector::ballDebug_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace ballDetector

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::ballDetector::ballDebug_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::ballDetector::ballDebug_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::ballDetector::ballDebug_<ContainerAllocator> > {
  static const char* value() 
  {
    return "f0dbcd340db400b8721875b15029f990";
  }

  static const char* value(const  ::ballDetector::ballDebug_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xf0dbcd340db400b8ULL;
  static const uint64_t static_value2 = 0x721875b15029f990ULL;
};

template<class ContainerAllocator>
struct DataType< ::ballDetector::ballDebug_<ContainerAllocator> > {
  static const char* value() 
  {
    return "ballDetector/ballDebug";
  }

  static const char* value(const  ::ballDetector::ballDebug_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::ballDetector::ballDebug_<ContainerAllocator> > {
  static const char* value() 
  {
    return "bool sendDebugImages\n\
bool sendDebugTimes \n\
\n\
";
  }

  static const char* value(const  ::ballDetector::ballDebug_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::ballDetector::ballDebug_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::ballDetector::ballDebug_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.sendDebugImages);
    stream.next(m.sendDebugTimes);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct ballDebug_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ballDetector::ballDebug_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::ballDetector::ballDebug_<ContainerAllocator> & v) 
  {
    s << indent << "sendDebugImages: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.sendDebugImages);
    s << indent << "sendDebugTimes: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.sendDebugTimes);
  }
};


} // namespace message_operations
} // namespace ros

#endif // BALLDETECTOR_MESSAGE_BALLDEBUG_H

