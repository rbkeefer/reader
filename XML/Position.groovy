class Position {
  int top
  int bottom
  int left
  int right

  static factory(inPosition)
  {
    if (! inPosition) throw new Exception("Must supply a Position to build a Position object");
    def pos = new Position()

    pos.top = Integer.parseInt(inPosition.top.text())
    pos.bottom = Integer.parseInt(inPosition.bottom.text())
    pos.left = Integer.parseInt(inPosition.left.text())
    pos.right = Integer.parseInt(inPosition.right.text())

    pos
  }

}
