#!/bin/bash
if [ $# -lt 3 ] ; then 
    echo "Usage : $0 <ECN_GW_Config_File> <PROD_LINE> <ENV>"
    echo "Example : $0 ....."
    echo "Exiting"
    exit 1
fi
ECN_List_Config=$1
PROD_LINE= `echo $2 | tr '[:upper:]' '[:lower:]'`
ENV= `echo $3 | tr '[:upper:]' '[:lower:]'`
TODAY=$(date + %Y%m%d)
HOST_NAME=`hostname`
ResultsLoc=CAMM_ECN_GW_Health_Check

mkdir -p $ResultsLoc

TempFile=./$ResultsLoc/TempFile_$Host_Name"_"$TODAY.txt
LogFile=./$ResultsLoc/HealthCheckLog_$HOST_NAME"_"$TODAY.txt
rm -f $TempFile $LogFile
touch $TempFile $LogFile

echo "kucch kucch"

if [ -f $ECN_List_Config ] ; then
    while read line
    do 
        read -ra inputElements <<< "$line"
        ecnName=${inputElements[3]}
        logPath=${inputElements[4]}
        logPath=`echo ${logPath} | tr -d "'"`
        wrapperLogPath=$LogPath/wrapper.log
        errorLogPath=$LogPath/error.log

        echo "health check started for GW: $ecnName" >> $LogFile
        echo "Calculating Exception and Error Count for GW: $ecnName" >> $LogFile

        exceptionCount_wr=`grep "Exceptio" $wrapperLogPath | wc -l`
        errorCount_wr=`grep -i "ERROR]" $wrapperLogPath | wc -l`
        exceptionCount_er=`grep "Exception" $errorLogPath | wc -l`
        errorCount_er= `grep -i "ERROR]" $errorLogPath | wc -l`

        exceptionCount=`expr $exceptionCount_wr + $exceptionCount_er`
        errorCount=`expr $errorCount_wr + $errorCount_er`
        echo "Exception Count: $exceptionCount" >> $LogFile
        echo "ErrorCount : $errorCount" >> $LogFile

        inputElementsCount=${#inputElements[@]}
        keywordsLog=""
        for ((counter =5;counter<$inputElementsCount;counter++))
        do 
            keyword=${inputElements|[$counter]}
            if [ -n "$keyword" ]; then
                echo "Searching for last occurence of keyword: $keyword in $wrapperLogPath" >> $LogFile
                echo "Log line for last occurence of keyword: $keyword in $wrapperLogPath" >>> $LogFile
                currentKeywordLog=`grep $keyword $wrapperLogPath | tail -l`
                echo "Log line for last occurence of keyword: $keyword in $wrapperLogPath is: $currentKeywordLog" >> $LogFile
                if [ -f $wrapperLogPath ]; then
                    if [ $keyword = "healthStatusList" ]; then
                        currentKeywordLog=`echo $currentKeywordLog | sed 's/GREEN/\<green\>GREEN\<\/green\>/g;s/YELLOW/\<yellow\>YELLOW\<\/yellow\>/g;
                        s/RED/\<red\>RED\<\/red\>/g;
                        s/BLACK/\gray\>BLACK\<\/gray\>/g'`
                    elif [ $keyword = "allObservedUp" ]; then
                        currentKeywordLog=`echo $currentKeywordLog | sed 's/allObservedUp: true/allObservedUp:\<green\>true\<\/green\>/g; s/allObservedUp: false/allObservedUp: \<red\>false\<\/red\>/g'`
                    fi 
                fi

                keywordsLog+="<B>$keyword: </B>"$currentKeywordLog"<br><br>"
            fi
        done
        
        echo "Overall Status: $ecnName|| $exceptionCount ($exceptionCount_wr + $exceptionCount_er)||$errorCount($errorCount_wr + $errorCount_er)||$keywordsLog" >> $LogFile
        echo "HealthCheckCompleted for GW: $ecnName" >>$LogFile
        echo "$ecnName||$exceptionCount ($exceptionCount_wr + $exceptionCount_er)||$errorCount ($errorCount_wr + $errorCount_er)||$keywordsLog" >> $TempFile
    done < <(cat $ECN_List_Config | grep -v "^$" | grep -v "^#" | grep -i $PROD_LINE | grep -i $ENV | grep -i $HOSTNAME)


    FinalHTML=./$ResultsLoc/HTMLReport_$HOSTNAME"_"$TODAY.html
    echo "<html><head><style>
        tale,th, td {
            border: 2px solid white;
            border-collapse: collapse;
            margin-bottom: 5px;
        }
        th,td{
            padding: 5px;
            text-align: center;
            font: 12px verdana, sans-serif;
        }
        green {
            background-color: lightgreen
        }
        red{
            background-color: red
        }
        yellow{
            background-color: yellow
        }
        black{
            background-color: gray
        }

        body{
            font: 15 px verdana, sans-serif;
        }
        </style></head><body>" >$FinalHTML
    
    echo "<table border =1 style=width:600 bgcolor=#DFDCE3>
        <tr><th colspan=30 bgcolor=#8497b0><B> `echo $PROD_LINE | tr [:lower:] [:upper:]` | `echo $ENV | tr [:lower:] [:upper:]` | `echo $HOST_NAME | tr [:lower:] [:upper:]` | `date` </B></th></tr>
        </table>" >>$FinalHTML
    echo "<table border =1 style=width:600 bgcolor=#DFDCE3" >> $FinalHTML

    echo "<tr bgcolor=#acb9ca>
        <td><b>ECN</b></td>
        <td><b>Exception Count (wrapper + error)</b></td>
        <td><b>Error Count (wrapper + error)</b></td>
        <td><b>Key Log Statements</b></td>
        </tr>" >>$FinalHTML
    while read INPUT ; do
        echo "<tr><td>${INPUT//||/</td><td>}</td></tr>" >>$FinalHTML
    done < <(cat $TempFile)
    echo "</table>" >>$FinalHTML

    rm -f $TempFile
else 
    echo "ERROR: ECN List file $ECN_List_Config not found"
fi 
echo "----- Health CheckUp Completed-----" >> LogFile


