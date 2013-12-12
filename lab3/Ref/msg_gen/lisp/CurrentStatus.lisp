; Auto-generated. Do not edit!


(cl:in-package Ref-msg)


;//! \htmlinclude CurrentStatus.msg.html

(cl:defclass <CurrentStatus> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (positions
    :reader positions
    :initarg :positions
    :type (cl:vector Ref-msg:Position)
   :initform (cl:make-array 0 :element-type 'Ref-msg:Position :initial-element (cl:make-instance 'Ref-msg:Position)))
   (checkpoints
    :reader checkpoints
    :initarg :checkpoints
    :type (cl:vector Ref-msg:Position)
   :initform (cl:make-array 0 :element-type 'Ref-msg:Position :initial-element (cl:make-instance 'Ref-msg:Position))))
)

(cl:defclass CurrentStatus (<CurrentStatus>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CurrentStatus>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CurrentStatus)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name Ref-msg:<CurrentStatus> is deprecated: use Ref-msg:CurrentStatus instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <CurrentStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:header-val is deprecated.  Use Ref-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'positions-val :lambda-list '(m))
(cl:defmethod positions-val ((m <CurrentStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:positions-val is deprecated.  Use Ref-msg:positions instead.")
  (positions m))

(cl:ensure-generic-function 'checkpoints-val :lambda-list '(m))
(cl:defmethod checkpoints-val ((m <CurrentStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:checkpoints-val is deprecated.  Use Ref-msg:checkpoints instead.")
  (checkpoints m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CurrentStatus>) ostream)
  "Serializes a message object of type '<CurrentStatus>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'positions))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'positions))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'checkpoints))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'checkpoints))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CurrentStatus>) istream)
  "Deserializes a message object of type '<CurrentStatus>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'positions) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'positions)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'Ref-msg:Position))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'checkpoints) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'checkpoints)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'Ref-msg:Position))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CurrentStatus>)))
  "Returns string type for a message object of type '<CurrentStatus>"
  "Ref/CurrentStatus")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CurrentStatus)))
  "Returns string type for a message object of type 'CurrentStatus"
  "Ref/CurrentStatus")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CurrentStatus>)))
  "Returns md5sum for a message object of type '<CurrentStatus>"
  "6e45f36f38d7d698ab2f081fcb41b647")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CurrentStatus)))
  "Returns md5sum for a message object of type 'CurrentStatus"
  "6e45f36f38d7d698ab2f081fcb41b647")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CurrentStatus>)))
  "Returns full string definition for message of type '<CurrentStatus>"
  (cl:format cl:nil "Header header~%Position[] positions~%Position[] checkpoints~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: Ref/Position~%float32 x~%float32 y~%float32 rot~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CurrentStatus)))
  "Returns full string definition for message of type 'CurrentStatus"
  (cl:format cl:nil "Header header~%Position[] positions~%Position[] checkpoints~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: Ref/Position~%float32 x~%float32 y~%float32 rot~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CurrentStatus>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'positions) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'checkpoints) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CurrentStatus>))
  "Converts a ROS message object to a list"
  (cl:list 'CurrentStatus
    (cl:cons ':header (header msg))
    (cl:cons ':positions (positions msg))
    (cl:cons ':checkpoints (checkpoints msg))
))
