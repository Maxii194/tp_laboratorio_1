#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "funciones.h"
#include "html.h"

void html_primerInstancia(char* path,FILE* pFile){

        fprintf(pFile,"<!DOCTYPE html>\n<!-- Template by Quackit.com -->\n<html lang='en'>\n<head>\n\t<meta charset='utf-8'>\n");
        fprintf(pFile,"\t<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n\t<meta name='viewport' content='width=device-width, initial-scale=1'>\n");
        fprintf(pFile,"\t<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n");
        fprintf(pFile,"\t<title>Lista peliculas</title>\n");
        fprintf(pFile,"\t<!-- Bootstrap Core CSS -->\n");
        fprintf(pFile,"\t<link href='css/bootstrap.min.css' rel='stylesheet'>\n");
        fprintf(pFile,"\t<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n");
        fprintf(pFile,"\t<link href='css/custom.css' rel='stylesheet'>\n");
        fprintf(pFile,"\t<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n");
        fprintf(pFile,"\t<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n");
        fprintf(pFile,"\t<!--[if lt IE 9]>\n");
        fprintf(pFile,"\t\t<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n");
        fprintf(pFile,"\t\t<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n");
        fprintf(pFile,"\t<![endif]-->\n</head>\n<body>\n\t<div class='container'>\n\t\t<div class='row'>\n\n\n");
        fprintf(pFile,"\n\t\t\t<article class='col-md-4 article-intro'>\n\t\t\t\t<a href='#'>\n");
        fprintf(pFile,"\t\t\t\t\t<img class='img-responsive img-rounded' src='");


}

void html_segundaInstancia(char* path,FILE* pFile){

    fprintf(pFile,"' alt=''>\n\t\t\t\t</a>\n\t\t\t\t<h3>\t\t\t\t\n\t\t\t\t\t<a href='#'>");

}

void html_terceraInstancia(char* path,FILE* pFile){

    fprintf(pFile,"</a>\n\t\t\t\t</h3>\n\t\t\t\t<ul>\n\t\t\t\t\t<li>Género:");
}

void html_cuartaInstancia(char* path,FILE* pFile){

    fprintf(pFile,"</li>\n\t\t\t\t\t<li>Puntaje:");

}

void html_quintaInstancia(char* path,FILE* pFile){

    fprintf(pFile,"</li>\n\t\t\t\t\t<li>Duración:");

}

void html_sextaInstancia(char* path,FILE* pFile){

    fprintf(pFile,"</li>\n\t\t\t\t</ul>\n\t\t\t\t<p>");
}

void html_septimaInstancia(char* path,FILE* pFile){

    fprintf(pFile,"</p>\n\t\t\t</article>\n\n\n\n\t\t</div>\n\t\t<!-- /.row -->\n\t</div>\n\t<!-- /.container -->\n\t");
    fprintf(pFile,"<!-- jQuery -->\n\t<script src='js/jquery-1.11.3.min.js'></script>\n\t<!-- Bootstrap Core JavaScript -->\n\t");
    fprintf(pFile,"<script src='js/bootstrap.min.js'></script>\n\t<!-- IE10 viewport bug workaround -->\n\t");
    fprintf(pFile,"<script src='js/ie10-viewport-bug-workaround.js'></script>\n\t");
    fprintf(pFile,"<!-- Placeholder Images -->\n\t<script src='js/holder.min.js'></script>\n</body>\n</html>");
}
