type direction =
  | Up
  | Left
  | Right
  | Down;

let to_dir (up :'a) (left :'a) (right :'a) (down :'a) (dir :'a) :option direction =>
  switch () {
    | _ when dir == up => Some Up
    | _ when dir == left => Some Left
    | _ when dir == right => Some  Right
    | _ when dir == down => Some Down
    | _ => None
  };

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

let grow (amount :int) (s :snek) :snek => {
  let old_len = Array.length s.segs;
  let new_len = old_len + amount;
  let tail = s.segs.((s.head + old_len - 1) mod old_len);
  let new_arr = Array.make new_len tail;
  /*
    to go down the length of the old snake,
    we start at s.head then go backwards
  */
  for raw_idx in 0 to (old_len - 1) {
    let old_idx = (s.head + old_len - raw_idx) mod old_len;
    let new_idx = new_len - raw_idx - 1;
    Array.set new_arr new_idx s.segs.(old_idx);
  };
  {
    head: new_len - 1,
    segs: new_arr,
  }
};


let crashed (s :snek) :bool => {
  /* indexed fold_left which i assumed would exist but does not */
  let foldli (fn :(int => 'a => 'b => 'a)) (default :'a) (arr :array 'b) :'a =>
    Array.fold_left (fun (i, r) v => (i + 1, fn i r v)) (0, default) arr |> snd;
  let (x, y) = s.segs.(s.head).pos;
  /* make sure the head can't crash into itself */
  let test index result seg => result || index != s.head && {
    let (seg_x, seg_y) = seg.pos;
    seg_x == x && seg_y == y
  };
  /* TODO: compiler is complaining about Array.exists? */
  foldli test false s.segs
};

