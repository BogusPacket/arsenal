

function loadHomepage(){
    $("#osinfo").html("<td>Hi</td>");
}

function preExec(){
    $("#radioset" ).buttonset();
    $("#draggable" ).draggable();
    $("#console").draggable();
    $("#runcmdbtn").button();
    $("#draggable").fadeIn();
    $('#console').hide();
    
}

function loadModule($module){
    $('#draggable').hide();
    $('#console').hide();
    $module.fadeIn();
}

$(document).ready(function() {
    
   
    preExec(); //////
    $('#calcbtn').click( function() {loadModule($('#draggable'));});
    
    $('#draggable').keydown(function(){
                        console.log('fuck');
                        if($('#radio1').is(':checked')){
                            document.getElementById('output1').value =   parseInt(document.getElementById('input1').value, 16);
                        }
                        else if($('#radio2').is(':checked')){
                            document.getElementById('output1').value = Number(document.getElementById('input1').value).toString(16) ;
                        }
                        
                    });
                    
                    $('#radio1').click(function(){currentbtn = $('#radio1');});
                    $('#radio2').click(function(){currentbtn = $('#radio2');});
                    
                    });




