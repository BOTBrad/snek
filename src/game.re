type state = {
  snek :(Snek.snek),
  board :(Board.board),
};

let step (d :Snek.direction) (g :state) :option state => {
  let b = g.board;
  let s = Snek.turn d g.snek;
  if (Snek.crashed s || Board.crashed s b) {
    if (Board.won s b) {
      print_endline "you win!"
    } else {
      /* TODO: replay temporarily broken */
      print_endline "you lost :(\nplay again? (y/n)"
    };
    None
  } else {
    let (b, s) =
      if (Board.hit_fruit s b) {
        (Board.new_fruit s b, Snek.grow 5 s)
      } else {
        (b, s)
      };
    Some {
      snek: s,
      board: b,
    }
  }
};

let make () :state => {
  let s = Snek.make 4 { pos: (5, 5), dir: Snek.Right };
  {
    snek: s,
    board: Board.make 20 20 s,
  }
};

