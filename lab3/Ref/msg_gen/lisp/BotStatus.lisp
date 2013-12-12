; Auto-generated. Do not edit!


(cl:in-package Ref-msg)


;//! \htmlinclude BotStatus.msg.html

(cl:defclass <BotStatus> (roslisp-msg-protocol:ros-message)
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
   (currentPosition
    :reader currentPosition
    :initarg :currentPosition
    :type Ref-msg:Position
    :initform (cl:make-instance 'Ref-msg:Position))
   (nextCheckpoint
    :reader nextCheckpoint
    :initarg :nextCheckpoint
    :type Ref-msg:Position
    :initform (cl:make-instance 'Ref-msg:Position))
   (checkpointIndex
    :reader checkpointIndex
    :initarg :checkpointIndex
    :type cl:fixnum
    :initform 0)
   (lap
    :reader lap
    :initarg :lap
    :type cl:fixnum
    :initform 0)
   (powerUp
    :reader powerUp
    :initarg :powerUp
    :type cl:fixnum
    :initform 0)
   (shotCount
    :reader shotCount
    :initarg :shotCount
    :type cl:fixnum
    :initform 0)
   (canRun
    :reader canRun
    :initarg :canRun
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass BotStatus (<BotStatus>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <BotStatus>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'BotStatus)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name Ref-msg:<BotStatus> is deprecated: use Ref-msg:BotStatus instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <BotStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:header-val is deprecated.  Use Ref-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'botID-val :lambda-list '(m))
(cl:defmethod botID-val ((m <BotStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:botID-val is deprecated.  Use Ref-msg:botID instead.")
  (botID m))

(cl:ensure-generic-function 'currentPosition-val :lambda-list '(m))
(cl:defmethod currentPosition-val ((m <BotStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:currentPosition-val is deprecated.  Use Ref-msg:currentPosition instead.")
  (currentPosition m))

(cl:ensure-generic-function 'nextCheckpoint-val :lambda-list '(m))
(cl:defmethod nextCheckpoint-val ((m <BotStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:nextCheckpoint-val is deprecated.  Use Ref-msg:nextCheckpoint instead.")
  (nextCheckpoint m))

(cl:ensure-generic-function 'checkpointIndex-val :lambda-list '(m))
(cl:defmethod checkpointIndex-val ((m <BotStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:checkpointIndex-val is deprecated.  Use Ref-msg:checkpointIndex instead.")
  (checkpointIndex m))

(cl:ensure-generic-function 'lap-val :lambda-list '(m))
(cl:defmethod lap-val ((m <BotStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:lap-val is deprecated.  Use Ref-msg:lap instead.")
  (lap m))

(cl:ensure-generic-function 'powerUp-val :lambda-list '(m))
(cl:defmethod powerUp-val ((m <BotStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:powerUp-val is deprecated.  Use Ref-msg:powerUp instead.")
  (powerUp m))

(cl:ensure-generic-function 'shotCount-val :lambda-list '(m))
(cl:defmethod shotCount-val ((m <BotStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:shotCount-val is deprecated.  Use Ref-msg:shotCount instead.")
  (shotCount m))

(cl:ensure-generic-function 'canRun-val :lambda-list '(m))
(cl:defmethod canRun-val ((m <BotStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:canRun-val is deprecated.  Use Ref-msg:canRun instead.")
  (canRun m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <BotStatus>) ostream)
  "Serializes a message object of type '<BotStatus>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'botID)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'currentPosition) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'nextCheckpoint) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'checkpointIndex)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'lap)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'powerUp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'shotCount)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'canRun) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <BotStatus>) istream)
  "Deserializes a message object of type '<BotStatus>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'botID)) (cl:read-byte istream))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'currentPosition) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'nextCheckpoint) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'checkpointIndex)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'lap)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'powerUp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'shotCount)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'canRun) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<BotStatus>)))
  "Returns string type for a message object of type '<BotStatus>"
  "Ref/BotStatus")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BotStatus)))
  "Returns string type for a message object of type 'BotStatus"
  "Ref/BotStatus")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<BotStatus>)))
  "Returns md5sum for a message object of type '<BotStatus>"
  "742eab62fbe4b8a5d8451d3c2f43cb20")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'BotStatus)))
  "Returns md5sum for a message object of type 'BotStatus"
  "742eab62fbe4b8a5d8451d3c2f43cb20")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<BotStatus>)))
  "Returns full string definition for message of type '<BotStatus>"
  (cl:format cl:nil "Header header~%uint8 botID~%Position currentPosition~%Position nextCheckpoint~%uint8 checkpointIndex~%uint8 lap~%uint8 powerUp~%uint8 shotCount~%bool canRun~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: Ref/Position~%float32 x~%float32 y~%float32 rot~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'BotStatus)))
  "Returns full string definition for message of type 'BotStatus"
  (cl:format cl:nil "Header header~%uint8 botID~%Position currentPosition~%Position nextCheckpoint~%uint8 checkpointIndex~%uint8 lap~%uint8 powerUp~%uint8 shotCount~%bool canRun~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: Ref/Position~%float32 x~%float32 y~%float32 rot~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <BotStatus>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'currentPosition))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'nextCheckpoint))
     1
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <BotStatus>))
  "Converts a ROS message object to a list"
  (cl:list 'BotStatus
    (cl:cons ':header (header msg))
    (cl:cons ':botID (botID msg))
    (cl:cons ':currentPosition (currentPosition msg))
    (cl:cons ':nextCheckpoint (nextCheckpoint msg))
    (cl:cons ':checkpointIndex (checkpointIndex msg))
    (cl:cons ':lap (lap msg))
    (cl:cons ':powerUp (powerUp msg))
    (cl:cons ':shotCount (shotCount msg))
    (cl:cons ':canRun (canRun msg))
))
