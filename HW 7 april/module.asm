.386
PUBLIC @CreateVectorB@16
PUBLIC @IntToOct@8 
PUBLIC @IsMin@8
PUBLIC @IsMax@8
PUBLIC @FindSaddlePoints@16

.model flat
.data

n dd 0
m dd 0
off dd 0
abc db "0123456789ABCDEF"
min dd 0
max dd 0

.code

@CreateVectorB@16 proc

  mov n, edx              
  mov ebx, ecx            
  mov eax, [esp + 4]
  mov m, eax             
  mov esi, [esp + 8]          

  mov eax, m             
  mov ecx, 4             
  mul ecx
  mov off, eax

  mov ecx, m

  beg1:           
    xor eax, eax          

    push ecx
    push ebx
    push esi

    mov ecx, n

    beg2:            
      mov esi, 0
      cmp [ebx], esi        
      jne jne1
        inc eax         
        jne1:
        add ebx, off    
    loop beg2

    pop esi
    pop ebx
    pop ecx

    mov [esi], eax         
    add esi, 4            
    add ebx, 4            
  loop beg1

  mov [esp + 8], esi  
  ret
@CreateVectorB@16 endp


@IntToOct@8 proc
      xor bl,bl
      mov [edx][11],bl
      mov eax, 11
 
     beg1:
        cmp eax, 0
          jle end1
          mov ebx, ecx
          and ebx, 7
          mov bl, abc[ebx]
          mov [edx][eax-1], bl
          shr ecx, 3
          dec eax
          jmp beg1
      end1:
      mov ebx, ecx
      shr ecx, 2
      and ebx, 7
      mov bl, abc[ebx]
      mov [edx][eax], bl
      xor eax,eax
     ret
  @IntToOct@8 endp

  @IsMin@8 proc
  ;ecx - N
  ;edx - M
  pop eax

  xor esi,esi
  xor ebx,ebx
  beg1:

  end1:

  mov eax, min
  ret
  @IsMin@8 endp

  @IsMax@8 proc

  ret
  @IsMax@8 endp


  @FindSaddlePoints@16 proc

  ret
  @FindSaddlePoints@16 endp

end