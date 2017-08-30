      program ExpCaracter
      implicit none
      !Utilizacion de cadenas de caracteres
      
      !Definicion
      character (5) :: a, b
      character :: resultado*25
      integer :: i
      
      !Asignacion
      a='hola'
      b='adios'
      
      resultado=trim(a)//' y '//trim(b)
      
      print *,'Cadena a: ', a
      print *,'Cadena b: ', b
      print *,'Resultado: ', resultado
      
      !Recorrido y algunas funciones
      do i=1, len(trim(resultado))
        print *, resultado(i:i)
      end do
      
      !asignacion de subcadenas
      a=resultado(8:)
      b=resultado(:4)
      
      print *, 'Cadena a: ', a
      print *, 'Cadena b: ', b
      print *, 'Resultado: ', resultado
      
      end program
