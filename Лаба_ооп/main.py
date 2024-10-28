import tkinter as tk
from tkinter import ttk
import mysql.connector

class Database:
    """класс для работы с бд"""

    def __init__(self, host="localhost",
                 user="root",
                 password="",
                 database="computer_parts"):
        self.conn = mysql.connector.connect(
            host=host,
            user=user,
            password=password,
            database=database
        )
        self.cursor = self.conn.cursor()

    def fetch_components(self):
        """получает все компоненты и их родительские связи из бд"""
        self.cursor.execute("SELECT id, name, parent_id FROM components")
        return self.cursor.fetchall()

    def close(self):
        """закрывает соединение с бд"""
        self.cursor.close()
        self.conn.close()


class ComputerApp:
    """класс для создания интерфейса приложения"""

    def __init__(self, root):
        self.root = root
        self.root.title("Компьютерные компоненты")

        # настраиваем treeview
        self.tree = ttk.Treeview(root)
        self.tree.pack(fill="both", expand=True)

        # подключаемся к бд и получаем данные
        self.db = Database()
        self.components = self.db.fetch_components()

        # создаем словарь для хранения id и родительских id
        self.nodes = {}

        # добавляем данные в treeview
        self.populate_tree()

    def populate_tree(self):
        """заполняет treeview данными из бд"""
        # находим корневые элементы (где parent_id is NULL)
        root_items = [comp for comp in self.components if comp[2] is None]

        # рекурсивно добавляем узлы в treeview
        for root_item in root_items:
            self.add_node(root_item)

    def add_node(self, component):
        """добавляет узел в treeview"""
        comp_id, name, parent_id = component

        # определяем родительский элемент в treeview
        parent_tree_id = "" if parent_id is None else self.nodes.get(parent_id)

        # добавляем элемент в treeview и сохраняем его id
        self.nodes[comp_id] = self.tree.insert(parent_tree_id, "end", text=name)

        # ищем дочерние элементы и добавляем их
        child_components = [comp for comp in self.components if comp[2] == comp_id]
        for child in child_components:
            self.add_node(child)

    def run(self):
        """запускает основной цикл приложения"""
        self.root.mainloop()
        self.db.close()


if __name__ == "__main__":
    root = tk.Tk()
    app = ComputerApp(root)
    app.run()