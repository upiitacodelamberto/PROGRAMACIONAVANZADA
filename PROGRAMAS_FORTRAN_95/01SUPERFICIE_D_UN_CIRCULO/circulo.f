      program circulo
      !
      !programa para calcular areas de circulos
      !
      !implicit none
      real::radio, superficie
      parameter (pi=3.1415926)
      !
      !visualizar un titulo cabecero
      !
      print*, 'SUPERFICIE DE UN CIRCULO'
      !
      !peticion de los datos
      !
      print*, 'Introducir el valor del radio (m):'
      read*, radio
      !
      !algoritmo
      superficie=pi*radio**2
      !
      !visualizar resultado
      !
      !print*, 'Para radio ', radio, ' la superficie es: ', superficie, 'm^{2}'
      print*,'Para radio ', radio
      print*,' la superficie es: ', superficie, 'm^{2}'
      end program circulo
