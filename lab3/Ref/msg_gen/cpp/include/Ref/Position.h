/* Auto-generated by genmsg_cpp for file /projects/ros/surfer-main/lab3/Ref/msg/Position.msg */
#ifndef REF_MESSAGE_POSITION_H
#define REF_MESSAGE_POSITION_H
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


namespace Ref
{
template <class ContainerAllocator>
struct Position_ {
  typedef Position_<ContainerAllocator> Type;

  Position_()
  : x(0.0)
  , y(0.0)
  , rot(0.0)
  {
  }

  Position_(const ContainerAllocator& _alloc)
  : x(0.0)
  , y(0.0)
  , rot(0.0)
  {
  }

  typedef float _x_type;
  float x;

  typedef float _y_type;
  float y;

  typedef float _rot_type;
  float rot;


  typedef boost::shared_ptr< ::Ref::Position_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::Ref::Position_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct Position
typedef  ::Ref::Position_<std::allocator<void> > Position;

typedef boost::shared_ptr< ::Ref::Position> PositionPtr;
typedef boost::shared_ptr< ::Ref::Position const> PositionConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::Ref::Position_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::Ref::Position_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace Ref

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::Ref::Position_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::Ref::Position_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::Ref::Position_<ContainerAllocator> > {
  static const char* value() 
  {
    return "03b81cae7f2c85f753929002066a5643";
  }

  static const char* value(const  ::Ref::Position_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x03b81cae7f2c85f7ULL;
  static const uint64_t static_value2 = 0x53929002066a5643ULL;
};

template<class ContainerAllocator>
struct DataType< ::Ref::Position_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Ref/Position";
  }

  static const char* value(const  ::Ref::Position_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::Ref::Position_<ContainerAllocator> > {
  static const char* value() 
  {
    return "float32 x\n\
float32 y\n\
float32 rot\n\
\n\
";
  }

  static const char* value(const  ::Ref::Position_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::Ref::Position_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::Ref::Position_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.x);
    stream.next(m.y);
    stream.next(m.rot);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct Position_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::Ref::Position_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::Ref::Position_<ContainerAllocator> & v) 
  {
    s << indent << "x: ";
    Printer<float>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<float>::stream(s, indent + "  ", v.y);
    s << indent << "rot: ";
    Printer<float>::stream(s, indent + "  ", v.rot);
  }
};


} // namespace message_operations
} // namespace ros

#endif // REF_MESSAGE_POSITION_H

