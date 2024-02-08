import tkinter as tk
from tkinter import ttk, Menu
from random import randint
from pynput import mouse
from PIL import ImageGrab


class MainWindow(tk.Tk):
    def __init__(self):
        #  Setting up the Window
        super().__init__()
        self.width = 570
        self.height = 370
        self.title('Color Palette')
        self.geometry(f'{self.width}x{self.height}')
        self.default_color = (255, 255, 255)  # Default color To display when program opens
        self.current_color = '#FFFFFF'
        self.current_selection = None
        self.mouse_listener = None
        self.menu_bar = Menu(self)

        self.create_top_menu()
        self.config(menu=self.menu_bar)
        '''
            Maybe add a function just for creating the gui?
        '''
        #  Setting-up top most container to store other TOP containers
        self.top_container = tk.Frame(self)
        self.top_container.pack(side=tk.TOP, pady=20)
        #  Top Left container to store the Canvas Panel
        self.canvas_frame = tk.Frame(self.top_container)
        self.canvas_frame.grid(row=0, column=0)
        #  Setting-up the Canvas Panel
        #  #{:02x} - produces a 2 digit hex value with a preceding 0
        self.color_canvas = tk.Canvas(self.canvas_frame, width=100, height=100,
                                      bg='#{:02x}{:02x}{:02x}'
                                      .format(self.default_color[0], self.default_color[1], self.default_color[2]))
        self.color_canvas.pack(padx=10, pady=10)

        self.label_frame = tk.Frame(self.top_container)
        self.label_frame.grid(row=0, column=1)

        self.color_label_rgb = tk.Label(self.label_frame, text=f'RGB:\t{self.default_color}')
        self.color_label_rgb.pack(side=tk.TOP, anchor=tk.W, padx=10)
        self.color_label_hex = tk.Label(self.label_frame,
                                        text='Hex:\t#{:02X}{:02X}{:02X}'
                                        .format(self.default_color[0], self.default_color[1], self.default_color[2]))
        self.color_label_hex.pack(side=tk.TOP, anchor=tk.W, padx=10)

        self.button_frame = tk.Frame(self.top_container)
        self.button_frame.grid(row=1, column=0, columnspan=2)

        self.new_button = tk.Button(self.button_frame, text='New Color')
        self.new_button.bind('<Button-1>', self.listen_for_click)
        self.new_button.grid(row=1, column=0, padx=(0, 5), pady=5)

        save_button = tk.Button(self.button_frame, text='Save Color')
        save_button.bind('<Button-1>', self.change_palette)
        save_button.grid(row=1, column=1, padx=(0, 5), pady=5)

        separator = ttk.Separator(self)
        separator.pack(fill='x', pady=10)

        self.bottom_container = tk.Frame(self)
        self.bottom_container.pack(pady=10)

        self.create_palette_array()

    def create_top_menu(self):
        # Create a top menu to load, save, always on top, options.
        file_menu = Menu(self.menu_bar, tearoff=0)
        self.menu_bar.add_cascade(label='File', menu=file_menu)
        file_menu.add_command(label='Exit', command=self.destroy)

    def change_color(self, color):
        hex_color = "#{:02X}{:02X}{:02X}".format(color[0], color[1], color[2])
        self.color_canvas.config(bg=hex_color)
        self.color_label_rgb.config(text=f'RGB:\t{color}')
        self.color_label_hex.config(text=f'Hex:\t{hex_color}')
        self.current_color = hex_color

    def create_palette_array(self, load=False):
        if load is False:
            color_array = []
            i = 0
            while i < 45:
                color_array.append((randint(0, 255), randint(0, 255), randint(0, 255)))
                i += 1
        else:
            color_array = load

        row = 0
        col = 0
        # palette = [[None for _ in range(15)] for _ in range(3)]
        for color in color_array:
            palette_panel = tk.Canvas(self.bottom_container, width=25, height=25,
                                      bg="#{:02x}{:02x}{:02x}".format(color[0], color[1], color[2]),
                                      relief='solid', borderwidth=2)
            palette_panel.bind("<Button-1>", lambda event, c=color: self.change_color(c))
            palette_panel.grid(row=row, column=col, padx=2, pady=2)
            palette_panel.bind("<Button-3>", lambda event, s=palette_panel: self.select_palette(s))
            # palette[row][col] = palette_panel
            col += 1
            if col == 15:
                row += 1
                col = 0
        # print(palette)

    def change_palette(self, event):
        # TODO: Change the palette color
        self.current_selection.config(bg=self.current_color)

    def select_palette(self, canvas_object):
        # TODO: Put current canvas object in a variable and show whats selected.
        if self.current_selection is None:
            self.current_selection = canvas_object
            self.current_selection.config(relief='raised')  # Select the new palette
            # print(self.current_selection)
        elif self.current_selection is not canvas_object:
            # print(self.current_selection)
            self.current_selection.config(relief='solid')  # Deselect the old palette
            canvas_object.config(relief='raised')  # Select the new palette
            self.current_selection = canvas_object
            # print(self.current_selection)
        else:
            print(f'{canvas_object} already selected.')

    def listen_for_click(self, event):
        if self.mouse_listener is None:
            self.mouse_listener = mouse.Listener(on_click=self.set_color_from_screen)
            self.mouse_listener.start()
            self.attributes('-topmost', True)

    def set_color_from_screen(self, x, y, button, clicked):
        if clicked and button == mouse.Button.left:
            selection_box = (x, y, x + 1, y + 1)
            image_grab = ImageGrab.grab(bbox=selection_box)
            image_rgb = image_grab.convert('RGB')
            r, g, b = image_rgb.getpixel((0, 0))
            self.change_color((r, g, b))
            if self.mouse_listener:
                self.mouse_listener.stop()
                self.mouse_listener = None
                #  self.attributes('-topmost', False)


if __name__ == "__main__":
    gui = MainWindow()
    gui.mainloop()
