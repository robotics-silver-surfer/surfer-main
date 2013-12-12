; Auto-generated. Do not edit!


(cl:in-package Ref-msg)


;//! \htmlinclude HoverBot.msg.html

(cl:defclass <HoverBot> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (botID
    :reader botID
    :initarg :botID
    :type cl:fixnum
    :initform 0)
   (checkpoint
    :reader checkpoint
    :initarg :checkpoint
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0))
   (powerup
    :reader powerup
    :initarg :powerup
    :type cl:fixnum
    :initform 0)
   (canRun
    :reader canRun
    :initarg :canRun
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass HoverBot (<HoverBot>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <HoverBot>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'HoverBot)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name Ref-msg:<HoverBot> is deprecated: use Ref-msg:HoverBot instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <HoverBot>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:header-val is deprecated.  Use Ref-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'botID-val :lambda-list '(m))
(cl:defmethod botID-val ((m <HoverBot>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:botID-val is deprecated.  Use Ref-msg:botID instead.")
  (botID m))

(cl:ensure-generic-function 'checkpoint-val :lambda-list '(m))
(cl:defmethod checkpoint-val ((m <HoverBot>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:checkpoint-val is deprecated.  Use Ref-msg:checkpoint instead.")
  (checkpoint m))

(cl:ensure-generic-function 'powerup-val :lambda-list '(m))
(cl:defmethod powerup-val ((m <HoverBot>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:powerup-val is deprecated.  Use Ref-msg:powerup instead.")
  (powerup m))

(cl:ensure-generic-function 'canRun-val :lambda-list '(m))
(cl:defmethod canRun-val ((m <HoverBot>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:canRun-val is deprecated.  Use Ref-msg:canRun instead.")
  (canRun m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <HoverBot>) ostream)
  "Serializes a message object of type '<HoverBot>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'botID)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'checkpoint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'checkpoint))
  (cl:let* ((signed (cl:slot-value msg 'powerup)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'canRun) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <HoverBot>) istream)
  "Deserializes a message object of type '<HoverBot>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'botID) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'checkpoint) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'checkpoint)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'powerup) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:setf (cl:slot-value msg 'canRun) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<HoverBot>)))
  "Returns string type for a message object of type '<HoverBot>"
  "Ref/HoverBot")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'HoverBot)))
  "Returns string type for a message object of type 'HoverBot"
  "Ref/HoverBot")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<HoverBot>)))
  "Returns md5sum for a message object of type '<HoverBot>"
  "f8385bf7604a2ee8d25d1f50a55982b3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'HoverBot)))
  "Returns md5sum for a message object of type 'HoverBot"
  "f8385bf7604a2ee8d25d1f50a55982b3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<HoverBot>)))
  "Returns full string definition for message of type '<HoverBot>"
  (cl:format cl:nil "Header header~%~%int8 botID~%~%int32[] checkpoint~%~%int8 powerup~%~%bool canRun~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'HoverBot)))
  "Returns full string definition for message of type 'HoverBot"
  (cl:format cl:nil "Header header~%~%int8 botID~%~%int32[] checkpoint~%~%int8 powerup~%~%bool canRun~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <HoverBot>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'checkpoint) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <HoverBot>))
  "Converts a ROS message object to a list"
  (cl:list 'HoverBot
    (cl:cons ':header (header msg))
    (cl:cons ':botID (botID msg))
    (cl:cons ':checkpoint (checkpoint msg))
    (cl:cons ':powerup (powerup msg))
    (cl:cons ':canRun (canRun msg))
))
