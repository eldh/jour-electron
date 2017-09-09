type t =
  | GetDir
  | SetDir string
  | GetPost
  | SetPost string
  | GetIndex;

let fire action =>
  switch action {
  | GetDir => Js.log "GetDir"
  | SetDir v => Js.log2 "SetDir" v
  | GetPost => Js.log "GetPost"
  | SetPost v => Js.log2 "SetPost" v
  | GetIndex => Js.log "GetIndex"
  };
