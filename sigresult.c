#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sigCont( int code ) {
    printf( ">>> SIGCONT received [%d]\n", code );
}

void sigTerm( int code ) {
    fprintf( stderr, ">>> SIGTERM received [%d]\n", code );
    
    // Pour forcer les appels sur les fonctions enregistrées par atexit
    exit( EXIT_SUCCESS );      
}

void exitFunction() {
    printf( "Exiting...\n" );
}

int main(void) {

    // On enregistre des fonctions à exécuter en cas de sortie normale du processus.
    atexit( exitFunction );

    // On enregistre quelques gestionnaires de signaux.
    signal( SIGTERM, &sigTerm );
    signal( SIGCONT, &sigCont );

    // Un message d'accueil.
    printf( "Welcome to SignalTest V1.0 :-)\n" );
    char buffer[100];

    // La boucle principale de notre console.
    while( true ) {
        printf( "Enter a command: " );
        fflush( stdout );
        scanf( "%s", buffer );

        if ( strcmp( buffer, "exit" ) == 0 ) break;
        if ( strcmp( buffer, "help" ) == 0 ) {
            // Affiche la liste des signaux supportés par le système.
            // Attention : ne marche que sur Linux/Unix !!!
            system( "bash -c \"kill -l\"" );
            continue;
        }

        int signalId = atoi( buffer );
        raise( signalId );              // C ISO 
        //kill( getpid(), signalId );   // POSIX (requière <unistd.h>)
    }

    return EXIT_SUCCESS;
}