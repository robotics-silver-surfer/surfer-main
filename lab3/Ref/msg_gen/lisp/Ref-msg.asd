
(cl:in-package :asdf)

(defsystem "Ref-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "BotStatus" :depends-on ("_package_BotStatus"))
    (:file "_package_BotStatus" :depends-on ("_package"))
    (:file "BotToRef" :depends-on ("_package_BotToRef"))
    (:file "_package_BotToRef" :depends-on ("_package"))
    (:file "HoverBot" :depends-on ("_package_HoverBot"))
    (:file "_package_HoverBot" :depends-on ("_package"))
    (:file "image" :depends-on ("_package_image"))
    (:file "_package_image" :depends-on ("_package"))
    (:file "Position" :depends-on ("_package_Position"))
    (:file "_package_Position" :depends-on ("_package"))
    (:file "controls" :depends-on ("_package_controls"))
    (:file "_package_controls" :depends-on ("_package"))
    (:file "CurrentStatus" :depends-on ("_package_CurrentStatus"))
    (:file "_package_CurrentStatus" :depends-on ("_package"))
  ))