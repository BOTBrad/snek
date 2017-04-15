type segment =
  (int, int);

type snek = {
  head :int,
  segs :array segment,
};

let make (len :int) (head :segment) :snek => {
  head: 0,
  segs: Array.make len head,
};

let at (x :int) (y :int) (s :snek) :bool =>
  Array.fold_left (fun con v => con || v == (x, y)) false s.segs;

