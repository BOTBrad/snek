type board = {
  width :int,
  height :int,
  fruit :(int, int),
};

let rec new_fruit (s :Snek.snek) (b :board) :board => {
  let x = Random.int b.width;
  let y = Random.int b.height;
  if (Snek.at x y s) {
    new_fruit s b
  } else {
    {
      ...b,
      fruit: (x, y),
    }
  }
};

let make (w :int) (h :int) (s :Snek.snek) :board =>
  new_fruit s {
    width: w,
    height: h,
    fruit: (0, 0),
  };

let crashed (s :Snek.snek) (b :board) :bool => {
  let (x, y) = s.segs.(s.head).pos;
  x < 0 || y < 0 || x >= b.width || y >= b.height
};

let hit_fruit (s :Snek.snek) (b :board) :bool =>
  s.segs.(s.head).pos == b.fruit;

