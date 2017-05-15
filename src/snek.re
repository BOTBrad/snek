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
  segs :list segment,
  grow :int,
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
  segs: [head],
  grow: len - 1,
};

let at (x :int) (y :int) (s :snek) :bool =>
  List.fold_left (fun con v => con || v.pos == (x, y)) false s.segs;

let hd (s :snek) :segment =>
  (List.hd s.segs);

let length (s :snek) :int =>
  (List.length s.segs);

let current_dir (s :snek) :direction =>
  (hd s).dir;

let turn (dir :direction) (s :snek) :snek => {
  let new_seg = move_seg dir (hd s);
  let (grow, segs) =
    if (s.grow > 0) {
      (s.grow - 1, s.segs)
    } else {
      (0, s.segs |> List.rev |> List.tl |> List.rev)
    };
  {
    segs: [new_seg, ...segs],
    grow: grow,
  }
};

let grow (amount :int) (s :snek) :snek => {
  ...s,
  grow: amount,
};

let crashed (s :snek) :bool => {
  let (x, y) = (hd s).pos;
  let tst seg => {
    let (seg_x, seg_y) = seg.pos;
    seg_x == x && seg_y == y;
  };
  List.exists tst (List.tl s.segs)
};

