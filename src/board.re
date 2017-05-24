type board = {
  width :int,
  height :int,
  fruit :(int, int),
};

let rec new_fruit (s :Snek.snek) (b :board) :board =>
  /* if the snake is as big as the board, give up */
  if (Snek.length s >= b.width * b.height) {
    {
      ...b,
      fruit: (-1, -1),
    }
  } else {
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

let hit_fruit (s :Snek.snek) (b :board) :bool =>
  (Snek.hd s).pos == b.fruit;

