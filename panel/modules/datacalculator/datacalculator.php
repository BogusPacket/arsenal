<?php
    $pg_script = "<script type=\"text/javascript\">"    .
            "$(function(){"  .
                "$(\"#radioset\").buttonset();"  .
                "$(\"#draggable\" ).draggable();"  .
                "$(\'#draggable\').keydown(function(){"   .
                    "if($(\'#radio1\').is(\':checked\')){"  .
                        "document.getElementById(\'output1\').value = parseInt(document.getElementById(\'input1\').value, 16);"  .
                    "}"  .
                    "else if($(\'#radio2\').is(\':checked\')){"  .
                        "document.getElementById(\'output1\').value = Number(document.getElementById(\'input1\').value).toString(16);" .
                    "}" .
                "});"  .                    
            "});"  .
            "</script>";
    
    $pg_html = "";