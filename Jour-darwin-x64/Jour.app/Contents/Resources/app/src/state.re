type post = {
  date: Date.t,
  content: string
};

type posts = array(Date.t);

let emptyPost = {date: Date.today(), content: ""};

let emptyPosts = [|Date.today()|];
