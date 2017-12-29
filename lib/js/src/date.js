'use strict';

var H = require("./h.js");

function add0(number) {
  var match = +(number > 9);
  if (match !== 0) {
    return H.i(number);
  } else {
    return "0" + H.i(number);
  }
}

function dateString(d) {
  return H.i(d[/* year */5]) + ("-" + (add0(d[/* month */4]) + ("-" + add0(d[/* date */3]))));
}

function getDay(d) {
  return new Date(dateString(d)).getDay() | 0;
}

function equals(d1, d2) {
  if (d1[/* year */5] === d2[/* year */5] && d1[/* month */4] === d2[/* month */4]) {
    return +(d1[/* date */3] === d2[/* date */3]);
  } else {
    return /* false */0;
  }
}

function getDayString(d) {
  var match = getDay(d);
  if (match > 6 || match < 0) {
    return "Funday";
  } else {
    switch (match) {
      case 0 : 
          return "Monday";
      case 1 : 
          return "Tuesday";
      case 2 : 
          return "Wednesday";
      case 3 : 
          return "Thursday";
      case 4 : 
          return "Friday";
      case 5 : 
          return "Saturday";
      case 6 : 
          return "Sunday";
      
    }
  }
}

function getMonthString(d) {
  var match = d[/* month */4];
  var switcher = match - 1 | 0;
  if (switcher > 11 || switcher < 0) {
    return "Cooluary";
  } else {
    switch (switcher) {
      case 0 : 
          return "January";
      case 1 : 
          return "February";
      case 2 : 
          return "March";
      case 3 : 
          return "April";
      case 4 : 
          return "May";
      case 5 : 
          return "June";
      case 6 : 
          return "July";
      case 7 : 
          return "August";
      case 8 : 
          return "September";
      case 9 : 
          return "October";
      case 10 : 
          return "November";
      case 11 : 
          return "December";
      
    }
  }
}

function getShortDayString(d) {
  var match = getDay(d);
  if (match > 6 || match < 0) {
    return "Fun";
  } else {
    switch (match) {
      case 0 : 
          return "Mon";
      case 1 : 
          return "Tue";
      case 2 : 
          return "Wed";
      case 3 : 
          return "Thu";
      case 4 : 
          return "Fri";
      case 5 : 
          return "Sat";
      case 6 : 
          return "Sun";
      
    }
  }
}

function format(format$1, d) {
  switch (format$1) {
    case 0 : 
        return dateString(d);
    case 1 : 
        return getDayString(d) + (", " + (H.i(d[/* date */3]) + (" " + getMonthString(d))));
    case 2 : 
        return H.i(d[/* hour */2]) + (":" + H.i(d[/* minute */1]));
    
  }
}

function get(year, month, date) {
  return /* record */[
          /* second */0,
          /* minute */0,
          /* hour */0,
          /* date */date,
          /* month */month,
          /* year */year
        ];
}

function now() {
  var second = ( new Date().getSeconds() );
  var minute = ( new Date().getMinutes() );
  var hour = ( new Date().getHours() );
  var date = ( new Date().getDate() );
  var month = ( new Date().getMonth() + 1 );
  var year = ( new Date().getFullYear() );
  return /* record */[
          /* second */second,
          /* minute */minute,
          /* hour */hour,
          /* date */date,
          /* month */month,
          /* year */year
        ];
}

function today() {
  var date = ( new Date().getDate() );
  var month = ( new Date().getMonth() + 1 );
  var year = ( new Date().getFullYear() );
  return /* record */[
          /* second */0,
          /* minute */0,
          /* hour */0,
          /* date */date,
          /* month */month,
          /* year */year
        ];
}

exports.add0              = add0;
exports.dateString        = dateString;
exports.getDay            = getDay;
exports.equals            = equals;
exports.getDayString      = getDayString;
exports.getMonthString    = getMonthString;
exports.getShortDayString = getShortDayString;
exports.format            = format;
exports.get               = get;
exports.now               = now;
exports.today             = today;
/* H Not a pure module */
