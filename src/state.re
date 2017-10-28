type post = {
  date: Date.t,
  content: string
};

type index = array Date.t;

let emptyPost = {date: Date.today (), content: ""};

let emptyIndex = [|Date.today ()|];
