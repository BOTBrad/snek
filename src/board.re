type board = {
  width: int,
  height: int,
};

let view (b :board) :array (array char) => {
  let height = b.height + 2;
  let width = b.width + 2;
  Array.init height (fun y =>
    if (y == 0 || y == height - 1) {
      Array.make width 'x'
    } else {
      Array.init width (fun x =>
        if (x == 0 || x == width - 1) {
          'x'
        } else {
          ' '
        }
      )
    }
  )
};

