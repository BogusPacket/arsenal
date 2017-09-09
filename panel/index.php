<!DOCTYPE html>
<html>
    <head>
        <title>Scanner</title>
        
        
         <script src="/themes/ThemeRoller/external/jquery/jquery.js"></script>
       
        <script src="/themes/ThemeRoller/jquery-ui.js"></script>
        <link rel="stylesheet" type="text/css" href="jquery-ui.theme.css"/>
        <link rel="stylesheet" type="text/css" href="main.css">  <!--TEMP-->
        
        
        
        
        
        
        <!----------------            META    ------------------->
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="stylesheet" type="text/css" href="arsenal.css">
        
        
        
        
        <!----------------            SCRIPTS    ------------------->
        <script type="text/javascript" src="arsenal.js"></script>
        <script>
            
            function hideAll(){
                $('#datacalculator').hide();
                $('#home').hide();
                $('#console').hide();
            }
            $( function() {
                hideAll();
                $('#dcbtn').click(function(){
                    hideAll();
                    $('#datacalculator').fadeIn();
                });
                $('#consolebtn').click(function(){
                    hideAll();
                    $('#console').fadeIn();
                });
		$("#homebtn").click(function(){
			hideAll();
			$('#home').fadeIn();
		});
  } );
  $currentbtn = 'r1';

  </script>
       
        
	
    

        
        <!--------------------        FONTS      ------------------->
        <link href="https://fonts.googleapis.com/css?family=Oswald" rel="stylesheet"/>
        <link href="https://fonts.googleapis.com/css?family=Exo:800" rel="stylesheet">
        <link href="https://fonts.googleapis.com/css?family=Cabin" rel="stylesheet">
        <link href="https://fonts.googleapis.com/css?family=Source+Code+Pro" rel="stylesheet">
        
        
        
        
        
        <!----------------            STYLE    ------------------->
        
        
    </head>
    <body>
         <div class="menubar">
            <h1>Arsenal</h1>
            <h2></h2>
        </div>
        <div class="mainmenu">
            <p id="homebtn" class="menuitem">Home</p>
            <p id="dcbtn" class="menuitem">Data Calculator</p>
            <p id="consolebtn" class="menuitem">Console</p>
        </div>
        
        
        <div class="module" id="home"><iframe src="http://104.36.18.36/Home/index.php"></iframe></div>
        <div class="module" id="datacalculator"><iframe id="ifr" style="width:100%; height:100%;" src="http://104.36.18.36/DataCalculator/index.php"></iframe></div>
        <iframe id="console" class="module" style="width:60%; height:80%;" src="http://104.36.18.36:3000/wetty/ssh/root"></iframe>
        <style>
            .module {
                height: 100%;
                width: 80%;
                position: absolute;
                left: 20%;
                top: 33px;
            }
            iframe {
		width: 100%;
		height: 100%;
		}

        </style>
        
        
        
    </body>
</html>

