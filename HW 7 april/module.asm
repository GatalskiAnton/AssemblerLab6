.386
PUBLIC @CreateVectorB@16
PUBLIC @IntToOct@8 
.model flat
.data
n db 0
m db 0
abc db "0123456789ABCDEF"
.code

@CreateVectorB@16 proc
;ecx - [][]
;edx - int
;stack - int
;stack int*



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


end