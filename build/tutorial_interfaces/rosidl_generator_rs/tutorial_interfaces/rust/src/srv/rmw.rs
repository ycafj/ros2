#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "tutorial_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tutorial_interfaces__srv__AddThreeInts_Request() -> *const std::ffi::c_void;
}

#[link(name = "tutorial_interfaces__rosidl_generator_c")]
extern "C" {
    fn tutorial_interfaces__srv__AddThreeInts_Request__init(msg: *mut AddThreeInts_Request) -> bool;
    fn tutorial_interfaces__srv__AddThreeInts_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AddThreeInts_Request>, size: usize) -> bool;
    fn tutorial_interfaces__srv__AddThreeInts_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AddThreeInts_Request>);
    fn tutorial_interfaces__srv__AddThreeInts_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AddThreeInts_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<AddThreeInts_Request>) -> bool;
}

// Corresponds to tutorial_interfaces__srv__AddThreeInts_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AddThreeInts_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub a: i64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub b: i64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub c: i64,

}



impl Default for AddThreeInts_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tutorial_interfaces__srv__AddThreeInts_Request__init(&mut msg as *mut _) {
        panic!("Call to tutorial_interfaces__srv__AddThreeInts_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AddThreeInts_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tutorial_interfaces__srv__AddThreeInts_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tutorial_interfaces__srv__AddThreeInts_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tutorial_interfaces__srv__AddThreeInts_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AddThreeInts_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AddThreeInts_Request where Self: Sized {
  const TYPE_NAME: &'static str = "tutorial_interfaces/srv/AddThreeInts_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tutorial_interfaces__srv__AddThreeInts_Request() }
  }
}


#[link(name = "tutorial_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tutorial_interfaces__srv__AddThreeInts_Response() -> *const std::ffi::c_void;
}

#[link(name = "tutorial_interfaces__rosidl_generator_c")]
extern "C" {
    fn tutorial_interfaces__srv__AddThreeInts_Response__init(msg: *mut AddThreeInts_Response) -> bool;
    fn tutorial_interfaces__srv__AddThreeInts_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AddThreeInts_Response>, size: usize) -> bool;
    fn tutorial_interfaces__srv__AddThreeInts_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AddThreeInts_Response>);
    fn tutorial_interfaces__srv__AddThreeInts_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AddThreeInts_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<AddThreeInts_Response>) -> bool;
}

// Corresponds to tutorial_interfaces__srv__AddThreeInts_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AddThreeInts_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sum: i64,

}



impl Default for AddThreeInts_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tutorial_interfaces__srv__AddThreeInts_Response__init(&mut msg as *mut _) {
        panic!("Call to tutorial_interfaces__srv__AddThreeInts_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AddThreeInts_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tutorial_interfaces__srv__AddThreeInts_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tutorial_interfaces__srv__AddThreeInts_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tutorial_interfaces__srv__AddThreeInts_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AddThreeInts_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AddThreeInts_Response where Self: Sized {
  const TYPE_NAME: &'static str = "tutorial_interfaces/srv/AddThreeInts_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tutorial_interfaces__srv__AddThreeInts_Response() }
  }
}






#[link(name = "tutorial_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__tutorial_interfaces__srv__AddThreeInts() -> *const std::ffi::c_void;
}

// Corresponds to tutorial_interfaces__srv__AddThreeInts
#[allow(missing_docs, non_camel_case_types)]
pub struct AddThreeInts;

impl rosidl_runtime_rs::Service for AddThreeInts {
    type Request = AddThreeInts_Request;
    type Response = AddThreeInts_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__tutorial_interfaces__srv__AddThreeInts() }
    }
}


