class Article
{
  int height
  int width
  int numColumns
  int avgDistBetweenColumns
  def headline
  def bodyTextList = []

  static factory(inArticle)
  {
    if (!inArticle) throw new Exception("Must supply an Article to build an Article object")

    def art = new Article()
    art.height = Integer.parseInt(inArticle.height.text())
    art.width = Integer.parseInt(inArticle.width.text())
    art.numColumns = Integer.parseInt(inArticle.numColumns.text())
    art.avgDistBetweenColumns = Integer.parseInt(inArticle.avgDistBetweenColumns.text())

    if (inArticle.Headline.Position)
      art.headline = Position.factory(inArticle.Headline.Position)
      
    inArticle.BodyText.Column.each { col ->
      art.bodyTextList << Position.factory(col.Position)
    }

    art
  }

}

