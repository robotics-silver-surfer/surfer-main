/* Auto-generated by genmsg_cpp for file /projects/ros/surfer-main/lab3/Ref/msg/BotToRef.msg */
#ifndef REF_MESSAGE_BOTTOREF_H
#define REF_MESSAGE_BOTTOREF_H
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

#include "std_msgs/Header.h"

namespace Ref
{
template <class ContainerAllocator>
struct BotToRef_ {
  typedef BotToRef_<ContainerAllocator> Type;

  BotToRef_()
  : header()
  , botID(0)
  {
  }

  BotToRef_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , botID(0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef uint8_t _botID_type;
  uint8_t botID;


  typedef boost::shared_ptr< ::Ref::BotToRef_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::Ref::BotToRef_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct BotToRef
typedef  ::Ref::BotToRef_<std::allocator<void> > BotToRef;

typedef boost::shared_ptr< ::Ref::BotToRef> BotToRefPtr;
typedef boost::shared_ptr< ::Ref::BotToRef const> BotToRefConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::Ref::BotToRef_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::Ref::BotToRef_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace Ref

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::Ref::BotToRef_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::Ref::BotToRef_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::Ref::BotToRef_<ContainerAllocator> > {
  static const char* value() 
  {
    return "2d11442c1144e852870ea968f1816b57";
  }

  static const char* value(const  ::Ref::BotToRef_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x2d11442c1144e852ULL;
  static const uint64_t static_value2 = 0x870ea968f1816b57ULL;
};

template<class ContainerAllocator>
struct DataType< ::Ref::BotToRef_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Ref/BotToRef";
  }

  static const char* value(const  ::Ref::BotToRef_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::Ref::BotToRef_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
uint8 botID\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
";
  }

  static const char* value(const  ::Ref::BotToRef_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::Ref::BotToRef_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::Ref::BotToRef_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::Ref::BotToRef_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.botID);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct BotToRef_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::Ref::BotToRef_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::Ref::BotToRef_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "botID: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.botID);
  }
};


} // namespace message_operations
} // namespace ros

#endif // REF_MESSAGE_BOTTOREF_H
