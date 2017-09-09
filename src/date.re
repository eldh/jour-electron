type formatters =
  | YYYYMMDD
  | DMY
  | HHmm;

type t = {
  second: int,
  minute: int,
  hour: int,
  date: int,
  month: int,
  year: int
};

let dateString d => H.i d.year ^ "-" ^ H.i d.month ^ "-" ^ H.i d.date;

let getDay d => int_of_float (Js.Date.getDay (Js.Date.fromString (dateString d)));

let equals d1 d2 => d1.year === d2.year && d1.month === d2.month && d1.date === d2.date;

let getDayString d =>
  switch (getDay d) {
  | 0 => "Monday"
  | 1 => "Tuesday"
  | 2 => "Wednesday"
  | 3 => "Thursday"
  | 4 => "Friday"
  | 5 => "Saturday"
  | 6 => "Sundat"
  | _ => "Funday"
  };

let getMonthString d =>
  switch d.month {
  | 0 => "January"
  | 1 => "February"
  | 2 => "March"
  | 3 => "April"
  | 4 => "May"
  | 5 => "June"
  | 6 => "July"
  | 7 => "August"
  | 8 => "September"
  | 9 => "October"
  | 10 => "November"
  | 11 => "December"
  | _ => "Cooluary"
  };

let getShortDayString d =>
  switch (getDay d) {
  | 0 => "Mon"
  | 1 => "Tue"
  | 2 => "Wed"
  | 3 => "Thu"
  | 4 => "Fri"
  | 5 => "Sat"
  | 6 => "Sun"
  | _ => "Fun"
  };

let format (format: formatters) d =>
  switch format {
  | YYYYMMDD => dateString d
  | DMY => getDayString d ^ ", " ^ H.i d.date ^ " " ^ getMonthString d
  | HHmm => H.i d.hour ^ ":" ^ H.i d.minute
  };

let get year month date => {
  let second = 0;
  let minute = 0;
  let hour = 0;
  let retDate = {second, minute, hour, date, month, year};
  retDate
};

let now () => {
  let second: int = [%bs.raw {| new Date().getSeconds() |}];
  let minute: int = [%bs.raw {| new Date().getMinutes() |}];
  let hour: int = [%bs.raw {| new Date().getHours() |}];
  let date: int = [%bs.raw {| new Date().getDate() |}];
  let month: int = [%bs.raw {| new Date().getMonth() |}];
  let year: int = [%bs.raw {| new Date().getFullYear() |}];
  let retDate = {second, minute, hour, date, month, year};
  retDate
};

let today () => {
  let second = 0;
  let minute = 0;
  let hour = 0;
  let date: int = [%bs.raw {| new Date().getDate() |}];
  let month: int = [%bs.raw {| new Date().getMonth() |}];
  let year: int = [%bs.raw {| new Date().getFullYear() |}];
  let retDate = {second, minute, hour, date, month, year};
  retDate
};
