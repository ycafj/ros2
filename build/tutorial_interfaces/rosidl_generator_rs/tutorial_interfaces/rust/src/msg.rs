#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to tutorial_interfaces__msg__Num

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Num {

    // This member is not documented.
    #[allow(missing_docs)]
    pub num: i64,

}



impl Default for Num {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Num::default())
  }
}

impl rosidl_runtime_rs::Message for Num {
  type RmwMsg = super::msg::rmw::Num;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        num: msg.num,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      num: msg.num,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      num: msg.num,
    }
  }
}


// Corresponds to tutorial_interfaces__msg__Sphere

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Sphere {

    // This member is not documented.
    #[allow(missing_docs)]
    pub center: geometry_msgs::msg::Point,


    // This member is not documented.
    #[allow(missing_docs)]
    pub radius: f64,

}



impl Default for Sphere {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Sphere::default())
  }
}

impl rosidl_runtime_rs::Message for Sphere {
  type RmwMsg = super::msg::rmw::Sphere;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        center: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.center)).into_owned(),
        radius: msg.radius,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        center: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.center)).into_owned(),
      radius: msg.radius,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      center: geometry_msgs::msg::Point::from_rmw_message(msg.center),
      radius: msg.radius,
    }
  }
}


// Corresponds to tutorial_interfaces__msg__Coord

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Coord {

    // This member is not documented.
    #[allow(missing_docs)]
    pub coord: [f32; 3],

}



impl Default for Coord {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Coord::default())
  }
}

impl rosidl_runtime_rs::Message for Coord {
  type RmwMsg = super::msg::rmw::Coord;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        coord: msg.coord,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        coord: msg.coord,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      coord: msg.coord,
    }
  }
}


