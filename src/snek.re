let module Board = Board;

let b : Board.board = {
  width: 20,
  height: 20,
};

let rec main () => {
  let line = read_line ();
  if (line != "exit") {
    let view = Board.view b;
    Array.iter (fun a => {
      Array.iter print_char a;
      print_char '\n'
    }) view;
    main ()
  }
};

main ();

