export SEG=/Users/rob/Development/workspace/Segmentation/Debug/Reader
export SEP=/Users/rob/Development/workspace/Separation/Debug/Reader
export CLS=/Users/rob/Development/workspace/Classification/Debug/Reader
export FRM=/Users/rob/Development/workspace/Framing/Debug/Reader

if [ "$#" == 2 ]; then
  if [ "$1" == -m ]; then
    echo "Run Manual $2"
    $SEG $2
    $SEP -m $2
    $CLS -m $2
    $FRM $2
  else
    echo "Usage: runPipeline [-m] imageFilename"
  fi
else
  echo "Run Automatic $1"
  $SEG $1
  $SEP $1
  $CLS $1
  $FRM $1
fi


