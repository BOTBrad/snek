type board = {
  width :int,
  height :int,
};

let view (b :board) :array (array char) =>
  Array.make b.height (Array.make b.width ' ');

