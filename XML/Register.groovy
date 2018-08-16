def refName = args[0]
def tgtName = args[1]

def refDocImage = new XmlParser().parse(refName)
def tgtDocImage = new XmlParser().parse(tgtName)

def refArticleList = []
def tgtArticleList = []

refDocImage.Article.each{ article ->
  refArticleList << Article.factory(article)
}

tgtDocImage.Article.each{ article ->
  tgtArticleList << Article.factory(article)
}

assert !refArticleList.empty
assert !tgtArticleList.empty

// println "REFERENCE"
// refArticleList.each{ article ->
  // println "Height: " + article.height
  // println "Width: " + article.width
  // println "NumCols: " + article.numColumns
  // println "AvgColSep: " + article.avgDistBetweenColumns
// }

// println "\nTARGET"
// tgtArticleList.each{ article ->
  // println "Height: " + article.height
  // println "Width: " + article.width
  // println "NumCols: " + article.numColumns
  // println "AvgColSep: " + article.avgDistBetweenColumns
// }

println "\n --- "
println refName + " with \n" + tgtName

int refNumber = 0
int tgtNumber = 0
int simRefNumber
int simTgtNumber

float s1, s2, s3
float similarity = 0.0
float lowSimilarity = 1000.0

refArticleList.each{ ref ->
  refNumber++ 

  tgtNumber = 0
  tgtArticleList.each{ tgt ->
    tgtNumber++

    s1 = ((ref.height/ref.width) - (tgt.height/tgt.width)).abs()
    s2 = (ref.numColumns - tgt.numColumns).abs()
    s3 = (ref.avgDistBetweenColumns - tgt.avgDistBetweenColumns).abs()

    similarity = s1 * (s2+s3)

    if ((similarity > 0.0) && (similarity < lowSimilarity))
    {
      lowSimilarity = similarity;
      simRefNumber = refNumber;
      simTgtNumber = tgtNumber;
    }
  }
}

println "Most Similar: Reference:[" + simRefNumber + "] with Target:[" + simTgtNumber +
        "] with a score of " + lowSimilarity
