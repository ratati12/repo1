call plug#begin('~/.vim/plugged')
Plug 'Valloric/YouCompleteMe'
Plug 'ErichDonGubler/vim-sublime-monokai'
call plug#end()


set expandtab
set smarttab
set softtabstop=4
set shiftwidth=4
set number
syntax on
colorscheme delek
set mouse=a
set foldcolumn=2
filetype plugin indent on "Включает определение типа файла, загрузку...
"... соответствующих ему плагинов и файлов отступов
set encoding=utf-8 "Ставит кодировку UTF-8
set nocompatible "Отключает обратную совместимость с Vi
syntax enable
set completeopt=menu
