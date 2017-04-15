type direction =
  | Up
  | Left
  | Right
  | Down;

let to_dir (up :'a) (left :'a) (right :'a) (down :'a) (dir :'a) :option direction =>
  if (dir == up) { Some Up } /* TODO: can this be less ugly? :( */
  else if (dir == left) { Some Left }
  else if (dir == right) { Some  Right }
  else if (dir == down) { Some Down }
  else { None };

type segment = {
  pos :(int, int),
  dir :direction,
};

type snek = {
  head :int,
  segs :array segment,
};

let reverse (d :direction) :direction =>
  switch (d) {
    | Up => Down
    | Left => Right
    | Right => Left
    | Down => Up
  };

let move_seg (d :direction) (s :segment) :segment => {
  let dir =
    if (d == reverse s.dir) {
      s.dir
    } else {
      d
    };
  let (x, y) = s.pos;
  let new_pos =
    switch (dir) {
      | Up => (x, y - 1)
      | Left => (x - 1, y)
      | Right => (x + 1, y)
      | Down => (x, y + 1)
    };
  {
    pos: new_pos,
    dir: dir,
  }
};

let make (len :int) (head :segment) :snek => {
  head: 0,
  segs: Array.make len head,
};

let at (x :int) (y :int) (s :snek) :bool =>
  Array.fold_left (fun con v => con || v.pos == (x, y)) false s.segs;

let current_dir (s :snek) :direction =>
  s.segs.(s.head).dir;

let turn (dir :direction) (s :snek) :snek => {
  let new_seg = move_seg dir s.segs.(s.head);
  let new_arr = Array.copy s.segs;
  let new_head = (s.head + 1) mod (Array.length new_arr);
  Array.set new_arr new_head new_seg;
  {
    head: new_head,
    segs: new_arr,
  }
};

