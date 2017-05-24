type state = {
  snek :(Snek.snek),
  board :(Board.board),
};

type victory_status =
  | Ok
  | Crashed
  | Won;

let check_victory (s :Snek.snek) (b :Board.board) :victory_status => {
  let (x, y) = (Snek.hd s).pos;
  if (x < 0 || y < 0 || x >= b.width || y >= b.height || (Snek.crashed s)) {
    Crashed
  } else if (Snek.length s >= b.width * b.height) {
    Won
  } else {
    Ok
  }
};

let step (d :Snek.direction) (g :state) :option state => {
  let b = g.board;
  let s = Snek.turn d g.snek;
  switch (check_victory s b) {
    | Won => {
      print_endline "you win!";
      None
    }
    | Crashed => {
      /* TODO: replay temporarily broken */
      print_endline "you lost :(\nplay again? (y/n)";
      None
    };
    | Ok => {
      let (b, s) = if (Board.hit_fruit s b) {
        (Board.new_fruit s b, Snek.grow 5 s)
      } else {
        (b, s)
      };
      Some {
        snek: s,
        board: b,
      }
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

